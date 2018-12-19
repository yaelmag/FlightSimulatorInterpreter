cmake_minimum_required(VERSION 3.13)
project(project1)

set(CMAKE_CXX_STANDARD 14)
find_package(Threads)
add_executable(project1 main.cpp Plus.cpp Plus.h Minus.cpp Minus.h Mult.cpp Mult.h Div.cpp Div.h ShuntingYard.cpp Num.h ShuntingYard.h OpenServerCommand.h OpenServerCommand.cpp)
target_link_libraries(project1 ${CMAKE_THREAD_LIBS_INIT})