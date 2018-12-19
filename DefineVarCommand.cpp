//
// Created by adi on 18/12/18.
//

#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(SymbolTable* varsMap) {
    this->varsMap = varsMap;
}

int DefineVarCommand:: doCommand(vector<string> info, int index) {
    this->varsMap->addVar(info[index], 0);
    // if there is just declaration of the var
    if (info[index + 1] == "\n") {
        return 3;
    }
    return 1;
}