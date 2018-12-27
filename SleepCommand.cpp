//
// Created by adi on 22/12/18.
//

#include "SleepCommand.h"
#include "PrintCommand.h"
#include <unistd.h>
#include <thread>

SleepCommand:: SleepCommand() = default;

int SleepCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    int value;
    if (info[index + 1] == "\n") {
        count = 2;
        // if the var in the map
        if (SymbolsTable::getInstance()->isSymbolExist(info[index])) {
            value = (int)SymbolsTable::getInstance()->getSymbolValue(info[index]);
          //if this is a number
        } else {
            value = stoi(info[index]);
        }
    } else {
        CheckExpressions check;
        vector<string> exp = check.getExpressions(info, index);
        if (exp.size() != 1) {
            __throw_invalid_argument("There are too many arguments");
        }
        count = check.getExpressionLength(exp[0]) + check.countCommas(info, index);
        count++;
        ShuntingYard s;
        value = (int)s.evaluate(exp[0]).evaluate();
    }
    //this_thread::sleep_for(chrono::milliseconds(value))
    usleep(value);
    return count;
}