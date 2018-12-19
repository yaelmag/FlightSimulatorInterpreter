//
// Created by adi on 18/12/18.
//

#include "VarCommand.h"

VarCommand::VarCommand(SymbolTable* varsMap) {
    this->varsMap = varsMap;
}

int VarCommand:: doCommand(vector<string> info, int index) {
    this->varsMap->addVar(info[index], 0);
    return 1;
}