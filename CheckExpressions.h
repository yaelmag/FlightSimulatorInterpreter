//
// Created by adi on 23/12/18.
//

#ifndef PROJECT1_CHECKEXPRESSIONS_H
#define PROJECT1_CHECKEXPRESSIONS_H

#include "SymbolTable.h"
#include <string.h>
#include <vector>

class CheckExpressions {

public:
    CheckExpressions();
    vector<string> getExpressions(vector<string> info, int index);
    string getNumber(string num);
    bool checkOperator(string s1, string s2);
};


#endif //PROJECT1_CHECKEXPRESSIONS_H
