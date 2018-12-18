//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_OPENSERVERCOMMAND_H
#define PROJECT1_OPENSERVERCOMMAND_H

#include "Command.h"

class OpenServerCommand : public Command {

public:
    OpenServerCommand();
    int doCommand(vector<string> info, int index, SymbolTable* varsMap);
};


#endif //PROJECT1_OPENSERVERCOMMAND_H
