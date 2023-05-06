//
// Created by kaladin on 06.05.23.
//

#include "HttpClientConnector.h"
#include "../../constant/http_constants.h"
#include "jsonrpccxx/server.hpp"

smart_aquarium_rpc::HttpClientConnector::HttpClientConnector(const std::string &host, int port) : httpClient(
        host, port) {}

std::string smart_aquarium_rpc::HttpClientConnector::Send(const std::string &request) {
    auto response = httpClient.Post(RPC_ENDPOINT, request,
                                    JSON_CONTENT_TYPE);

    if (!response || static_cast<RPC_STATUSES>(response->status)
                     != smart_aquarium_rpc::RPC_STATUSES::SUCCESS_STATUS) {
        throw jsonrpccxx::JsonRpcException(static_cast<int>(RPC_STATUSES::CLIENT_ERROR),
                                           "Error when sending rpc message, received " +
                                           std::to_string(response->status));
    }

    return response->body;
}
