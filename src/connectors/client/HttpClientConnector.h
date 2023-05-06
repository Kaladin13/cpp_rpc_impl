//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_HTTPCLIENTCONNECTOR_H
#define RPC_TEST_HTTPCLIENTCONNECTOR_H

#include "jsonrpccxx/iclientconnector.hpp"
#include "cpp-httplib/httplib.h"

namespace smart_aquarium_rpc {

    class HttpClientConnector : public jsonrpccxx::IClientConnector {

        httplib::Client httpClient;

    public:
        explicit HttpClientConnector(const std::string &host, int port);

        std::string Send(const std::string &request) override;
    };
}


#endif //RPC_TEST_HTTPCLIENTCONNECTOR_H
