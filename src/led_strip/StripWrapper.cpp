//
// Created by kaladin on 11.05.23.
//

#include <bits/sigaction.h>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include "StripWrapper.h"
#include "led_colors.h"

#define ARRAY_SIZE(stuff)       (sizeof(stuff) / sizeof(stuff[0]))

StripWrapper::StripWrapper(int width, int gpioPin) : width(width), gpio_pin(gpioPin) {
    led_string = {
            .freq = WS2811_TARGET_FREQ,
            .dmanum = 10,
            .channel =
                    {
                            [0] =
                                    {
                                            .gpionum = gpioPin,
                                            .invert = 0,
                                            .count = width,
                                            .strip_type = WS2811_STRIP_GBR,
                                            .brightness = 255,
                                    },
                            [1] =
                                    {
                                            .gpionum = 0,
                                            .invert = 0,
                                            .count = 0,
                                            .brightness = 0,
                                    },
                    },
    };

    matrix = new ws2811_led_t(sizeof(ws2811_led_t) * width);

    setup_handlers();
}

void StripWrapper::matrix_render() {
    for (int x = 0; x < width; x++) {
        led_string.channel[0].leds[x] = matrix[x];
    }

}

void StripWrapper::matrix_clear() {
    for (int i = 0; i < width; ++i) {
        matrix[i] = LED_COLORS::BLACK;
    }
}

void StripWrapper::ctrl_c_handler(int signum) {
    (void) (signum);
    is_running = false;
}

void StripWrapper::setup_handlers() {
    struct sigaction sa =
            {
                    .sa_handler = ctrl_c_handler,
            };

    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
}

void StripWrapper::init() {
    ws2811_led_t status;

    status = ws2811_init(&led_string);

    if (status != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n",
                ws2811_get_return_t_str(static_cast<const ws2811_return_t>(status)));
        exit(status);
    }
}

void StripWrapper::red() {
    for (int i = 0; i < width; ++i) {
        matrix[i] = LED_COLORS::RED;
    }

    matrix_render();
    ws2811_render(&led_string);
}




