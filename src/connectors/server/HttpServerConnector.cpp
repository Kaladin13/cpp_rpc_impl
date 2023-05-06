//
// Created by kaladin on 06.05.23.
//

#include "HttpServerConnector.h"
#include "../../constant/http_constants.h"

smart_aquarium_rpc::HttpServerConnector::HttpServerConnector(jsonrpccxx::JsonRpcServer &server, int port) :
        rpcServer(server), port(port), thread(), httpServer() {
    initRoutes();
}

void smart_aquarium_rpc::HttpServerConnector::initRoutes() {
    httpServer.Post(RPC_ENDPOINT, [this](const httplib::Request &req, httplib::Response &res) {
        postAction(req, res);
    });
}

void smart_aquarium_rpc::HttpServerConnector::postAction(const httplib::Request &req, httplib::Response &res) {
    res.status = static_cast<int>(smart_aquarium_rpc::RPC_STATUSES::SUCCESS_STATUS);

    res.set_content(rpcServer.HandleRequest(req.body), JSON_CONTENT_TYPE);
}

void smart_aquarium_rpc::HttpServerConnector::stopListening() {
    if (httpServer.is_running()) {
        httpServer.stop();
        thread.join();

        std::cout << "Server stopped listening" << std::endl;
    }
}

bool smart_aquarium_rpc::HttpServerConnector::startListening() {
    if (httpServer.is_running()) {
        return false;
    }

    this->thread = std::thread([this]() { this->httpServer.listen(HOST, port); });
    return true;
}
