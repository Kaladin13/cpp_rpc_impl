//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_HTTP_CONSTANTS_H
#define RPC_TEST_HTTP_CONSTANTS_H

#include <string>

namespace smart_aquarium_rpc {
    inline static const std::string JSON_CONTENT_TYPE = "application/json";

    inline static const std::string RPC_ENDPOINT = "/json-rpc";

    inline static const std::string HOST = "localhost";

    enum class RPC_STATUSES {
        SUCCESS_STATUS = 200,
        CLIENT_ERROR = -32003,
    };
}

#endif //RPC_TEST_HTTP_CONSTANTS_H
