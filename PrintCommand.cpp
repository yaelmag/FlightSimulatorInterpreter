//
// Created by adi on 20/12/18.
//

#include "PrintCommand.h"
#include <iostream>

PrintCommand:: PrintCommand() = default;

int PrintCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    if (info[index + 1] == "\n") {
        count = 2;
        double value;
        // if the var in the map
        if (SymbolsTable::getInstance()->isSymbolExist(info[index])) {
            value = SymbolsTable::getInstance()->getSymbolValue(info[index]);
            cout<<value<<endl;
          // if this is a string
        } else if (info[index].at(0) == '"') {
            string messege = info[index].substr(1, info[index].length() - 2);
            cout<<messege<<endl;
          // if this is a number
        } else {
            value = stod(info[index]);
            cout << value << endl;
        }
    } else {
        CheckExpressions check;
        vector<string> exp = check.getExpressions(info, index);
        if (exp.size() != 1) {
            __throw_invalid_argument("There are too many arguments");
        }
        count = check.getExpressionLength(exp[0]);
        count++;
        ShuntingYard s;
        double num = s.evaluate(exp[0]).evaluate();
        cout<<num<<endl;
    }
    return count;
}