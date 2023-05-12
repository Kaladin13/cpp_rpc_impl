//
// Created by kaladin on 12.05.23.
//

#include "LedService.h"

LedService::LedService(const StripWrapper &stripWrapper) : stripWrapper(stripWrapper) {
    this->stripWrapper.init();
}

bool LedService::changeColor(const LedColor& ledColor) {
    LED_COLORS color;

    if (ledColor.colorName == "red") {
        color = LED_COLORS::RED;
    } else if (ledColor.colorName == "orange") {
        color = LED_COLORS::ORANGE;
    } else if (ledColor.colorName == "green") {
        color = LED_COLORS::GREEN;
    } else if (ledColor.colorName == "purple") {
        color = LED_COLORS::PURPLE;
    } else {
        return false;
    }

    return stripWrapper.custom(color);
}

bool LedService::turnOff() {
    return stripWrapper.off();
}
