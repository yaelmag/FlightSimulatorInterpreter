//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_VARCOMMAND_H
#define PROJECT1_VARCOMMAND_H
#include "Command.h"
#include "SymbolTable.h"

class DefineVarCommand : public Command {
SymbolTable* varsMap;
public:
    DefineVarCommand(SymbolTable* varsMap);
    int doCommand(vector<string> info, int index);
};


#endif //PROJECT1_VARCOMMAND_H
