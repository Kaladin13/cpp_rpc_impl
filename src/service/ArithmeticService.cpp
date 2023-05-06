//
// Created by kaladin on 06.05.23.
//

#include "ArithmeticService.h"

int smart_aquarium_rpc::ArithmeticService::sum(smart_aquarium_rpc::Arithmetic expression) {
    return expression.left + expression.right;
}
