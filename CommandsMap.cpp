//
// Created by adi on 18/12/18.
//

#include "CommandsMap.h"

CommandsMap::CommandsMap() {
    VarBindMap varBindMap = VarBindMap();
    SymbolTable varsMap = SymbolTable();

    OpenServerCommand* openDataServer = new OpenServerCommand(&varsMap, &varBindMap);
    commands.insert(pair<string, Command*>("openDataServer", openDataServer));
    ConnectCommand* connect = new ConnectCommand(&varsMap, &varBindMap);
    commands.insert(pair<string, Command*>("connect", connect));
    DefineVarCommand* var = new DefineVarCommand(&varsMap);
    commands.insert(pair<string, Command*>("var", var));
    EqualOperatorCommand* equal = new EqualOperatorCommand(&varsMap, &varBindMap);
    commands.insert(pair<string, Command*>("=", equal));
    PrintCommand* print = new PrintCommand(&varsMap);
    commands.insert(pair<string, Command*>("print", print));
    SleepCommand* sleep = new SleepCommand(&varsMap);
    commands.insert(pair<string, Command*>("sleep", sleep));
}

map<string, Command*> CommandsMap:: getMap() {
    return this->commands;
}