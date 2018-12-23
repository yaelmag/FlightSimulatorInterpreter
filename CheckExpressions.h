//
// Created by adi on 23/12/18.
//

#ifndef PROJECT1_CHECKEXPRESSIONS_H
#define PROJECT1_CHECKEXPRESSIONS_H

#include "SymbolTable.h"
#include <string.h>
#include <vector>

class CheckExpressions {
SymbolTable varsMap;

public:
    CheckExpressions(SymbolTable &varsMap);
    vector<string> getExpressions(vector<string> info, int index);
    string getNumber(SymbolTable map, string num);
    bool checkOperator(string s1, string s2);
};


#endif //PROJECT1_CHECKEXPRESSIONS_H
