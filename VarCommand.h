//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_VARCOMMAND_H
#define PROJECT1_VARCOMMAND_H
#include "Command.h"
#include "SymbolTable.h"

class VarCommand : public Command {
public:
    VarCommand();
    int doCommand(vector<string> info, int index, SymbolTable* varsMap);
};


#endif //PROJECT1_VARCOMMAND_H
