cmake_minimum_required(VERSION 3.13)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp ShuntingYard.cpp Expression.h BinaryExpression.h BaseExpression.h Num.cpp OpenDataServer.cpp)