//
// Created by adi on 17/12/18.
//

#include "iostream"
#include "OpenServerCommand.h"

int OpenServerCommand:: doCommand(vector<string> info, int index) {
    cout<<"in openDataServer"<<endl;
    int arg1, arg2, count;
    if (info.at(index + 2) == "\n") {
        count = 3;
        try {
            arg1 = stoi(info.at(index));
            arg2 = stoi(info.at(index+1));
        } catch (...) {
            __throw_invalid_argument("invalid type of argument (required int)");
        }
    } else {
        CheckExpressions c;
        ShuntingYard s;
        
        vector<string> exp = c.getExpressions(info, index);
        if (exp.size() != 2) {
            __throw_invalid_argument("The number of arguments invalid");
        }
        arg1 = (int) s.evaluate(exp[0]).evaluate();
        arg2 = (int) s.evaluate(exp[1]).evaluate();
        count = c.getExpressionLength(exp[0]) + c.getExpressionLength(exp[1]) +
                c.countCommas(info, index) + 1;
    }
    this->dataReaderServer.setPort(arg1);
    this->dataReaderServer.readFromClient();
    cout<<"end openServerCommand"<<endl;
    cout<<count<<endl;
    return count;
}