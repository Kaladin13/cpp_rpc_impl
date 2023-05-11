//
// Created by kaladin on 06.05.23.
//

#include "ArithmeticService.h"


int smart_aquarium_rpc::ArithmeticService::sum(smart_aquarium_rpc::Arithmetic expression) {
    stripWrapper.red();
    return expression.left + expression.right;
}

smart_aquarium_rpc::ArithmeticService::ArithmeticService(const StripWrapper &stripWrapper) : stripWrapper(
        stripWrapper) {}
