//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H
#include "Command.h"
#include "VarBindMap.h"
#include "SymbolTable.h"

class ConnectCommand : public Command{
SymbolTable *varsMap;
VarBindMap *varBindMap;
public:
    ConnectCommand(SymbolTable *varsMap, VarBindMap *varBindMap);
    int doCommand(vector<string> info, int index);
};


#endif //PROJECT1_CONNECTCOMMAND_H
