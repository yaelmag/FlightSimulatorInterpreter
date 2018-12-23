//
// Created by adi on 23/12/18.
//

#include "ConditionParser.h"

ConditionParser:: ConditionParser(string booleanExpression, CommandsMap &commands) {
    this->booleanExpression = booleanExpression;
    this->commands = commands;
}
