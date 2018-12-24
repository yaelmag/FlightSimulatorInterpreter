//
// Created by adi on 20/12/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H
#include "SymbolTable.h"
#include "Command.h"

class PrintCommand : public Command {
SymbolTable *varsMap;

public:
    PrintCommand(SymbolTable *varsMap);
    int doCommand(vector<string> info, int index);
};


#endif //PROJECT1_PRINTCOMMAND_H
