//
// Created by adi on 18/12/18.
//

#include "VarCommand.h"

VarCommand::VarCommand() = default;

int VarCommand:: doCommand(vector<string> info, int index, SymbolTable* varsMap) {
    varsMap->addVar(info[index], 0);
    return 1;
}