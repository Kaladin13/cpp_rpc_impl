//
// Created by kaladin on 12.05.23.
//

#ifndef RPC_TEST_LEDCOLOR_H
#define RPC_TEST_LEDCOLOR_H

#include <string>
#include "nlohmann/json.hpp"

struct LedColor {
    std::string colorName{};
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(LedColor, colorName)

#endif //RPC_TEST_LEDCOLOR_H
