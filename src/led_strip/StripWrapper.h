//
// Created by kaladin on 11.05.23.
//

#ifndef RPC_TEST_STRIPWRAPPER_H
#define RPC_TEST_STRIPWRAPPER_H


#include "rpi_ws281x/ws2811.h"
#include "led_colors.h"

class StripWrapper {
    const int width;

    const int gpio_pin;

    ws2811_t led_string;

    bool is_running;

public:
    StripWrapper(int width, int gpioPin);

    virtual ~StripWrapper();

    void init();

    void red();

    void purple();

    void orange();

    bool custom(LED_COLORS color);

    bool off();
};


#endif //RPC_TEST_STRIPWRAPPER_H
