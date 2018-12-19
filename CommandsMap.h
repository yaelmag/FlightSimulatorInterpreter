//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_COMMANDMAP_H
#define PROJECT1_COMMANDMAP_H
#include <string>
#include <vector>
#include <map>
#include "Command.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "EqualOperatorCommand.h"
#include "Expression.h"
#include "VarBindMap.h"
#include "SymbolTable.h"

using namespace std;

class CommandsMap {
map<string, Command*> commands;
public:
    CommandsMap();
    map<string, Command*> getMap();
};


#endif //PROJECT1_COMMANDMAP_H
