//
// Created by adi on 25/12/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(vector<string> boolExp) : ConditionParser(boolExp) {}

int IfCommand:: doCommand(vector<string> info, int index) {
    int endIf;
    // represent if we get to the end of the If
    bool flag = false;
    Parser* parser = Parser::getInstance();

    if (this->condition->evaluate()) {
        endIf = parser->runner(info, index);
        flag = true;
    }

    // if we don't enter to the If
    if (!flag) {
        while (info[index] != "}") {
            index++;
        }
        endIf = index;
    }

    endIf += 2;
    return endIf;
}