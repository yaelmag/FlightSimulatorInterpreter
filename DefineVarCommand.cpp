//
// Created by adi on 18/12/18.
//

#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand() = default;

int DefineVarCommand:: doCommand(vector<string> info, int index) {
    SymbolsTable::getInstance()->setSymbol(info[index], 0);
    // if there is just declaration of the var
    if (info[index + 1] == "\n") {
        return 2;
    }
    return 1;
}