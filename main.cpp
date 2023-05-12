#include "jsonrpccxx/client.hpp"
#include "jsonrpccxx/server.hpp"
#include "./src/service/ArithmeticService.h"
#include "src/connectors/client/HttpClientConnector.h"
#include "src/connectors/server/HttpServerConnector.h"
#include "src/constant/http_constants.h"
#include "src/led_strip/StripWrapper.h"
#include "src/service/LedService.h"
#include <iostream>

using namespace std::chrono_literals;

int main() {
    jsonrpccxx::JsonRpc2Server jsonRpcServer;

    StripWrapper strip = StripWrapper(60, 18);

    LedService ledService(strip);

    jsonRpcServer.Add("changeColor", jsonrpccxx::GetHandle(&LedService::changeColor,
                                                           ledService), {"ledColor"});

    jsonRpcServer.Add("turnOff", jsonrpccxx::GetHandle(&LedService::turnOff,
                                                       ledService));

    smart_aquarium_rpc::HttpServerConnector serverConnector(jsonRpcServer, 8083);

    smart_aquarium_rpc::HttpClientConnector clientConnector(smart_aquarium_rpc::HOST, 8083);

    std::cout << "Starting server listening... " << std::boolalpha << serverConnector.startListening() << std::endl;

    // wait for server to start
    std::this_thread::sleep_for(10s);

    // json-rpc v2 https://www.jsonrpc.org/specification
    jsonrpccxx::JsonRpcClient jsonRpcClient(clientConnector, jsonrpccxx::version::v2);


    LedColor ledColor;
    ledColor.colorName = "red";

//    bool result = jsonRpcClient.CallMethod<bool>(1, "changeColor", {ledColor});

//    std::cout << "result: " << result << std::endl;

    return 0;
}
