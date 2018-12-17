cmake_minimum_required(VERSION 3.12)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h Lexer.cpp Lexer.h Parser.cpp Parser.h)