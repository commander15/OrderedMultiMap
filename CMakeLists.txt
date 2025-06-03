cmake_minimum_required(VERSION 3.20)

project(OrderedMultiMap)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_executable(CLI main.cpp
    orderedmultimap.h)

target_link_libraries(CLI PRIVATE Qt::Core)
