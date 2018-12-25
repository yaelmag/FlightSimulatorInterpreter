//
// Created by adi on 23/12/18.
//

#ifndef PROJECT1_CONDITIONPARSER_H
#define PROJECT1_CONDITIONPARSER_H

#include "Command.h"
#include "CommandsMap.h"
#include "BooleanExpression.h"
#include "Parser.h"



class ConditionParser : public Command{

    vector<Expression*> createExpressions(vector<string> boolExp);
    BooleanExpression* createCondition(vector<string> boolExp);

public:
    BooleanExpression* condition;
    ConditionParser(vector<string> boolExp);
    int doCommand(vector<string> info, int index) override = 0;
};


#endif //PROJECT1_CONDITIONPARSER_H
