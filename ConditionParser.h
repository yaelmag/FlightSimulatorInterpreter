//
// Created by adi on 23/12/18.
//

#ifndef PROJECT1_CONDITIONPARSER_H
#define PROJECT1_CONDITIONPARSER_H

#include "Command.h"
#include "CommandsMap.h"
#include "BooleanExpression.h"



class ConditionParser : public Command{
BooleanExpression* condition;
CommandsMap commands;

public:
    ConditionParser(vector<string> boolExp, CommandsMap &commands);
    vector<Expression*> createExpressions(vector<string> boolExp);
    BooleanExpression* createCondition(vector<string> boolExp);
    int doCommand(vector<string> info, int index) override = 0;
};


#endif //PROJECT1_CONDITIONPARSER_H
