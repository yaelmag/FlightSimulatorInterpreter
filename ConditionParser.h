//
// Created by adi on 23/12/18.
//

#ifndef PROJECT1_CONDITIONPARSER_H
#define PROJECT1_CONDITIONPARSER_H

#include "Command.h"
#include "CommandsMap.h"

class ConditionParser : public Command{
string booleanExpression;
CommandsMap commands;

public:
    ConditionParser(string booleanExpression, CommandsMap &commands);
    int virtual doCommand(vector<string> info, int index) = 0;
};


#endif //PROJECT1_CONDITIONPARSER_H
