//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_ARITHMETIC_H
#define RPC_TEST_ARITHMETIC_H

#include "nlohmann/json.hpp"

namespace smart_aquarium_rpc {

    struct Arithmetic{
        int left{};
        int right{};
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Arithmetic, left, right)
} // smart_aquarium_rpc

#endif //RPC_TEST_ARITHMETIC_H
