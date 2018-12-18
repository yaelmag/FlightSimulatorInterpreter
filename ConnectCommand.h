//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H
#include "Command.h"

class ConnectCommand : public Command{

public:
    ConnectCommand();
    int doCommand(vector<string> info, int index, SymbolTable* varsMap);
};


#endif //PROJECT1_CONNECTCOMMAND_H
