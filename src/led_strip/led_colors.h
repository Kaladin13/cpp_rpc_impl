//
// Created by kaladin on 11.05.23.
//

#ifndef RPC_TEST_LED_COLORS_H
#define RPC_TEST_LED_COLORS_H

#include "rpi_ws281x/ws2811.h"

enum LED_COLORS {
    RED = 0x00000020,
    ORANGE = 0x00001020,
    YELLOW = 0x00002020,
    GREEN = 0x00002000,
    PURPLE = 0x00100010,
    BLACK = 0x00000000,
    BLUE = 0x00200000,
    PINK = 0x00200010,
    WHITE= 0x00101010
};

#endif //RPC_TEST_LED_COLORS_H
