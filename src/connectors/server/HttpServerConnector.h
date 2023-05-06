//
// Created by kaladin on 06.05.23.
//

#ifndef RPC_TEST_HTTPSERVERCONNECTOR_H
#define RPC_TEST_HTTPSERVERCONNECTOR_H

#include <thread>
#include "jsonrpccxx/server.hpp"
#include "cpp-httplib/httplib.h"

namespace smart_aquarium_rpc {

    class HttpServerConnector {

        std::thread thread;
        jsonrpccxx::JsonRpcServer &rpcServer;
        httplib::Server httpServer;
        int port;

        void initRoutes();

        void postAction(const httplib::Request &req,
                        httplib::Response &res);

        void stopListening();

    public:
        explicit HttpServerConnector(jsonrpccxx::JsonRpcServer &server, int port);

        virtual ~HttpServerConnector() { stopListening(); }

        bool startListening();
    };
}

#endif //RPC_TEST_HTTPSERVERCONNECTOR_H
