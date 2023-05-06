//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_ARITHMETICSERVICE_H
#define RPC_TEST_ARITHMETICSERVICE_H

#include "../dto/Arithmetic.h"

namespace smart_aquarium_rpc {

    class ArithmeticService {
    public:
        int sum(Arithmetic expression);
    };
}


#endif //RPC_TEST_ARITHMETICSERVICE_H
