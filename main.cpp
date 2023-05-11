#include "jsonrpccxx/client.hpp"
#include "jsonrpccxx/server.hpp"
#include "./src/service/ArithmeticService.h"
#include "src/connectors/client/HttpClientConnector.h"
#include "src/connectors/server/HttpServerConnector.h"
#include "src/constant/http_constants.h"
#include "rpi_ws281x/ws2811.h"
#include <iostream>

using namespace std::chrono_literals;

int main() {
    jsonrpccxx::JsonRpc2Server jsonRpcServer;

    smart_aquarium_rpc::ArithmeticService arithmeticService;

    bool added = jsonRpcServer.Add("sum", jsonrpccxx::GetHandle(&smart_aquarium_rpc::ArithmeticService::sum,
                                                                arithmeticService),
                                   {"expression"});

    assert(added);

    smart_aquarium_rpc::HttpServerConnector serverConnector(jsonRpcServer, 8083);

    smart_aquarium_rpc::HttpClientConnector clientConnector(smart_aquarium_rpc::HOST, 8083);

    std::cout << "Starting server listening... " << std::boolalpha << serverConnector.startListening() << std::endl;

    // wait for server to start
    std::this_thread::sleep_for(1s);

    // json-rpc v2 https://www.jsonrpc.org/specification
    jsonrpccxx::JsonRpcClient jsonRpcClient(clientConnector, jsonrpccxx::version::v2);

    smart_aquarium_rpc::Arithmetic expression;

    expression.left = 767;
    expression.right = 721;

    int result = jsonRpcClient.CallMethod<int>(1, "sum", {expression});

//    std::cout << "result: " << result << std::endl;

    assert(result == (expression.right + expression.left));

    return 0;
}
