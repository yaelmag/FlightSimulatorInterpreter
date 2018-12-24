//
// Created by adi on 23/12/18.
//

#include "ConditionParser.h"
#include "Num.h"
#include "ShuntingYard.h"
#include "Greater.h"
#include "GreaterEqual.h"
#include "Smaller.h"
#include "SmallerEqual.h"
#include "Equal.h"
#include "NotEqual.h"
#include "Expression.h"

ConditionParser:: ConditionParser(vector<string> boolExp, CommandsMap &commands) {
    double left, right;
    ShuntingYard s;
    left = s.evaluate(boolExp[0]).evaluate();
    right = s.evaluate(boolExp[0]).evaluate();
    if (boolExp[1] == ">") {
        this->booleanExpression = new Greater(new Num(left), new Num(right));
    } else if (boolExp[1] == ">=") {
        this->booleanExpression =  new GreaterEqual(new Num(left), new Num(right));
    } else if (boolExp[1] == "<") {
        this->booleanExpression =  new Smaller(new Num(left), new Num(right));
    } else if (boolExp[1] == "<=") {
        this->booleanExpression =  new SmallerEqual(new Num(left), new Num(right));
    } else if (boolExp[1] == "==") {
        this->booleanExpression =  new Equal(new Num(left), new Num(right));
    } else if (boolExp[1] == "!=") {
        this->booleanExpression =  new NotEqual(new Num(left), new Num(right));
    }
    this->commands = commands;
}

