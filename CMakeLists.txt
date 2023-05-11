cmake_minimum_required(VERSION 3.18)
project(rpc_test)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(
        "include" "vendor"
)

add_executable(rpc_test main.cpp src/connectors/client/HttpClientConnector.cpp
        src/connectors/client/HttpClientConnector.h src/constant/http_constants.h
        src/connectors/server/HttpServerConnector.cpp src/connectors/server/HttpServerConnector.h
        src/dto/Arithmetic.cpp src/dto/Arithmetic.h src/service/ArithmeticService.cpp src/service/ArithmeticService.h src/led_strip/StripWrapper.cpp src/led_strip/StripWrapper.h src/led_strip/led_colors.h)

target_link_libraries(rpc_test ${CMAKE_SOURCE_DIR}/libws2811.a)
