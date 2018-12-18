//
// Created by adi on 18/12/18.
//

#include "CommandsMap.h"

CommandsMap::CommandsMap() {
    OpenServerCommand* openDataServer = new OpenServerCommand();
    commands["openDataServer"] = openDataServer;
    ConnectCommand* connect = new ConnectCommand();
    commands["connect"] = connect;
    VarCommand* var = new VarCommand();
    commands["var"] = var;
    EqualOperatorCommand* equal = new EqualOperatorCommand();
    commands["="] = equal;
}

map<string, Command*> CommandsMap:: getMap() {
    return this->commands;
}