//
// Created by adi on 22/12/18.
//

#include "SleepCommand.h"
#include "PrintCommand.h"
#include <unistd.h>

SleepCommand:: SleepCommand(SymbolTable &varsMap) {
    this->varsMap = varsMap;
}

int SleepCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    int value;
    if (info[index + 1] == "\n") {
        count = 3;
        // if the var in the map
        if (varsMap.getMap().count(info[index]) != 0) {
            value = (int)varsMap.getVarValue(info[index]);
          //if this is a number
        } else {
            value = stoi(info[index]);
        }
    } else {
        //todo
        //להעביר את הפונקציה של תקינות ביטוי לתוך הקלאס שיעלי עשתה
        vector<string> exp = getExpressions(info, index);
        if (exp.size() != 1) {
            __throw_invalid_argument("There are too many arguments");
        }
        count = 2 + exp[0].length();
        //todo
        //לקרוא למה שיעלי עשתה כדי לפרש את הביטוי
        int num = (int)0;
    }
    sleep(value);
    return count;
}

//TODO: THE FUNCTION GETEXPRESSION - RECIEVE THE DATA AND RETURN THE EXPRESSIONS.
//TODO: UPDATE THE TABLE
//TODO: OPERATORS