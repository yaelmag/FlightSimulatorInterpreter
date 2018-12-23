//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_OPENSERVERCOMMAND_H
#define PROJECT1_OPENSERVERCOMMAND_H

#include "Command.h"
#include "VarBindMap.h"
#include "SymbolTable.h"

class OpenServerCommand : public Command {
SymbolTable varsMap;
VarBindMap varBindMap;

public:
    OpenServerCommand(SymbolTable &varsMap, VarBindMap &varBindMap);
    int doCommand(vector<string> info, int index);
};


#endif //PROJECT1_OPENSERVERCOMMAND_H
