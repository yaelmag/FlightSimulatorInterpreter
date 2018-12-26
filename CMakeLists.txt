cmake_minimum_required(VERSION 3.12.3)
project(project1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(project1 main.cpp Lexer.h Lexer.cpp PrintCommand.cpp PrintCommand.h SleepCommand.cpp
        SleepCommand.h CommandsMap.h CommandsMap.cpp EqualOperatorCommand.cpp EqualOperatorCommand.h
        ConnectCommand.h ConnectCommand.cpp Parser.h Parser.cpp OpenServerCommand.cpp
        OpenServerCommand.h DefineVarCommand.cpp DefineVarCommand.h SymbolTable.cpp SymbolTable.h
        Command.h VarBindMap.cpp VarBindMap.h Server.cpp DataReaderServer.cpp DataReaderServer.h
        Server.h PrintCommand.h PrintCommand.cpp SleepCommand.cpp SleepCommand.h
        CheckExpressions.cpp CheckExpressions.h ConditionParser.h ConditionParser.cpp
        ShuntingYard.cpp ShuntingYard.h Plus.cpp Plus.h Minus.cpp Minus.h Mult.cpp Mult.h Div.cpp
        Div.h BooleanExpression.h BooleanExpression.cpp Greater.cpp Greater.h GreaterEqual.cpp
        GreaterEqual.h Equal.cpp Equal.h NotEqual.cpp NotEqual.h Smaller.cpp Smaller.h
        SmallerEqual.cpp SmallerEqual.h SymbolsTable.cpp SymbolsTable.h)