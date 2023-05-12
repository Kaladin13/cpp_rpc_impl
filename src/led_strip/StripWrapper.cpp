//
// Created by kaladin on 11.05.23.
//

#include <cstdio>
#include <cstdlib>
#include "StripWrapper.h"
#include "led_colors.h"

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

    is_running = false;
}

void StripWrapper::init() {
    ws2811_return_t status;

    status = ws2811_init(&led_string);

    if (status != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n",
                ws2811_get_return_t_str(status));
        exit(status);
    }

    is_running = true;
}

void StripWrapper::red() {
    for (int i = 0; i < width; ++i) {
        led_string.channel[0].leds[i] = LED_COLORS::RED;
    }

    ws2811_render(&led_string);
}

bool StripWrapper::off() {
    if (is_running) {
        for (int i = 0; i < width; ++i) {
            led_string.channel[0].leds[i] = LED_COLORS::BLACK;
        }

        ws2811_return_t res = ws2811_render(&led_string);

        if (res != WS2811_SUCCESS) {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(res));
            exit(res);
        }

        ws2811_fini(&led_string);

        is_running = false;
    }

    return true;
}

void StripWrapper::purple() {
    for (int i = 0; i < width; ++i) {
        led_string.channel[0].leds[i] = LED_COLORS::PURPLE;
    }
}

void StripWrapper::orange() {
    for (int i = 0; i < width; ++i) {
        led_string.channel[0].leds[i] = LED_COLORS::ORANGE;
    }
}

bool StripWrapper::custom(LED_COLORS color) {
    if (!is_running) {
        init();
    }

    for (int i = 0; i < width; ++i) {
        led_string.channel[0].leds[i] = color;
    }

    ws2811_return_t res = ws2811_render(&led_string);

    return res == WS2811_SUCCESS;
}

StripWrapper::~StripWrapper() {
    off();
}



