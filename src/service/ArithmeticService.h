//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_ARITHMETICSERVICE_H
#define RPC_TEST_ARITHMETICSERVICE_H

#include "../dto/Arithmetic.h"
#include "../led_strip/StripWrapper.h"

namespace smart_aquarium_rpc {

    class ArithmeticService {
        StripWrapper stripWrapper;
    public:
        int sum(Arithmetic expression);

        explicit ArithmeticService(const StripWrapper &stripWrapper);
    };
}


#endif //RPC_TEST_ARITHMETICSERVICE_H
