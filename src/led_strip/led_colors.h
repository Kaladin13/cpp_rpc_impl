//
// Created by kaladin on 11.05.23.
//

#ifndef RPC_TEST_LED_COLORS_H
#define RPC_TEST_LED_COLORS_H

#include "rpi_ws281x/ws2811.h"

enum LED_COLORS {
    RED = 0x00200000,
    ORANGE = 0x00201000,
    YELLOW = 0x00202000,
    GREEN = 0x00002000,
    PURPLE = 0x00100010,
    BLACK = 0x00000000
};

#endif //RPC_TEST_LED_COLORS_H
