//
// Created by adi on 20/12/18.
//

#ifndef PROJECT1_PRINTCOMMAND_H
#define PROJECT1_PRINTCOMMAND_H
#include "SymbolTable.h"
#include "Command.h"

class PrintCommand : public Command {
SymbolTable varsMap;

public:
    PrintCommand(SymbolTable &varsMap);
    int doCommand(vector<string> info, int index);
    vector<string> getExpressions(vector<string> info, int index);
    string getNumber(SymbolTable map, string num);
    bool checkOperator(string s1, string s2);
};


#endif //PROJECT1_PRINTCOMMAND_H
