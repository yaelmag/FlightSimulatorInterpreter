//
// Created by adi on 18/12/18.
//

#include "CommandsMap.h"

CommandsMap::CommandsMap() {

    OpenServerCommand* openDataServer = new OpenServerCommand();
    commands.insert(pair<string, Command*>("openDataServer", openDataServer));
    ConnectCommand* connect = new ConnectCommand();
    commands.insert(pair<string, Command*>("connect", connect));
    DefineVarCommand* var = new DefineVarCommand();
    commands.insert(pair<string, Command*>("var", var));
    EqualOperatorCommand* equal = new EqualOperatorCommand();
    commands.insert(pair<string, Command*>("=", equal));
    PrintCommand* print = new PrintCommand();
    commands.insert(pair<string, Command*>("print", print));
    SleepCommand* sleep = new SleepCommand();
    commands.insert(pair<string, Command*>("sleep", sleep));
}

map<string, Command*> CommandsMap:: getMap() {
    return this->commands;
}