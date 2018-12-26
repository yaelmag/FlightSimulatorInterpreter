//
// Created by adi on 24/12/18.
//

#include "WhileCommand.h"

WhileCommand:: WhileCommand(vector<string> boolExp) : ConditionParser(boolExp) {}

int WhileCommand:: doCommand(vector<string> info, int index) {
    int endLoop;
    Parser* parser = Parser::getInstance();
    // represent if we already get to the end of the loop once
    bool flag = false;
    cout<<this->condition->evaluate()<<endl;
    while (this->condition->evaluate()) {
        if (!flag) {
            endLoop = parser->runner(info, index);
            flag = true;
        } else {
            parser->runner(info, index);
        }
    }

    // if we don't enter to the loop even once
    if (!flag) {
        while (info[index] != "}") {
            index++;
        }
        endLoop = index;
    }

    endLoop += 2;
    return endLoop;
}
