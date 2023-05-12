//
// Created by kaladin on 12.05.23.
//

#ifndef RPC_TEST_LEDSERVICE_H
#define RPC_TEST_LEDSERVICE_H


#include "../led_strip/StripWrapper.h"
#include "../dto/LedColor.h"

class LedService {
    StripWrapper stripWrapper;

public:
    explicit LedService(const StripWrapper &stripWrapper);

    bool changeColor(const LedColor& ledColor);

    bool turnOff();
};


#endif //RPC_TEST_LEDSERVICE_H
