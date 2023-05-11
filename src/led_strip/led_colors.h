//
// Created by kaladin on 11.05.23.
//

#ifndef RPC_TEST_LED_COLORS_H
#define RPC_TEST_LED_COLORS_H

#include "rpi_ws281x/ws2811.h"

int dotspos[] = {0, 1, 2, 3, 4, 5, 6, 7};

enum LED_COLORS {
    RED = 0x00200000,
    ORANGE = 0x00201000,
    YELLOW = 0x00202000,
    GREEN = 0x00002000,
    PURPLE = 0x00100010,
    BLACK = 0x00000000
};

ws2811_led_t dotcolors[] =
        {
                0x00200000,  // red
                0x00201000,  // orange
                0x00202000,  // yellow
                0x00002000,  // green
                0x00002020,  // lightblue
                0x00000020,  // blue
                0x00100010,  // purple
                0x00200010,  // pink
        };

ws2811_led_t dotcolors_rgbw[] =
        {
                0x00200000,  // red
                0x10200000,  // red + W
                0x00002000,  // green
                0x10002000,  // green + W
                0x00000020,  // blue
                0x10000020,  // blue + W
                0x00101010,  // white
                0x10101010,  // white + W

        };

#endif //RPC_TEST_LED_COLORS_H
