//
// Created by adi on 18/12/18.
//

#include "CommandsMap.h"

CommandsMap::CommandsMap() {
    VarBindMap varBindMap = VarBindMap();
    SymbolTable varsMap = SymbolTable();

    OpenServerCommand* openDataServer = new OpenServerCommand(&varsMap, &varBindMap);
    commands["openDataServer"] = openDataServer;
    ConnectCommand* connect = new ConnectCommand(&varsMap, &varBindMap);
    commands["connect"] = connect;
    DefineVarCommand* var = new DefineVarCommand(&varsMap);
    commands["var"] = var;
    EqualOperatorCommand* equal = new EqualOperatorCommand(&varsMap, &varBindMap);
    commands["="] = equal;
    //BindCommand* = bind = new BindCommand
}

map<string, Command*> CommandsMap:: getMap() {
    return this->commands;
}