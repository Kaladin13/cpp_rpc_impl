//
// Created by kaladin on 11.05.23.
//

#ifndef RPC_TEST_STRIPWRAPPER_H
#define RPC_TEST_STRIPWRAPPER_H


#include "rpi_ws281x/ws2811.h"

class StripWrapper {
    const int width;

    const int gpio_pin;

    ws2811_t led_string;
    ws2811_led_t *matrix;

    bool is_running;

    void matrix_render();

    void matrix_clear();

    void ctrl_c_handler(int signum);

//    void setup_handlers();

public:
    StripWrapper(int width, int gpioPin);

    void init();
    void red();
};


#endif //RPC_TEST_STRIPWRAPPER_H
