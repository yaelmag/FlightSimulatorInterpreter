cmake_minimum_required(VERSION 3.12.3)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp CommandExpression.cpp CommandExpression.h Lexer.h Lexer.cpp
        CommandsMap.h CommandsMap.cpp EqualOperatorCommand.cpp EqualOperatorCommand.h
        ConnectCommand.h ConnectCommand.cpp Parser.h Parser.cpp OpenServerCommand.cpp
        OpenServerCommand.h DefineVarCommand.cpp DefineVarCommand.h SymbolTable.cpp SymbolTable.h
        Command.h VarBindMap.cpp VarBindMap.h)
