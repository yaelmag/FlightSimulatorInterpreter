//
// Created by adi on 20/12/18.
//

#include "PrintCommand.h"
#include <iostream>

PrintCommand:: PrintCommand(SymbolTable &varsMap) {
    this->varsMap = varsMap;
}

int PrintCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    if (info[index + 1] == "\n") {
        count = 3;
        double value;
        // if the var in the map
        if (varsMap.getMap().count(info[index]) != 0) {
            value = varsMap.getVarValue(info[index]);
            cout<<value<<endl;
          // if this is a string
        } else if (info[index].at(0) == '"') {
            cout<<info[index]<<endl;
          // if this is a number
        } else {
            value = stod(info[index]);
            cout << value << endl;
        }
    } else {
        CheckExpressions check = CheckExpressions(varsMap);
        vector<string> exp = check.getExpressions(info, index);
        if (exp.size() != 1) {
            __throw_invalid_argument("There are too many arguments");
        }
        count = 2 + exp[0].length();
        //todo
        //לקרוא למה שיעלי עשתה כדי לפרש את הביטוי
        double num = 0;
        cout<<num<<endl;
    }
    return count;
}
