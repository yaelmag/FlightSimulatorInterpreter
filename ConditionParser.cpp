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
#include "SymbolsTable.h"
#include "Var.h"

ConditionParser:: ConditionParser(vector<string> boolExp, CommandsMap &commands) {
    this->condition = this->createCondition(boolExp);
    this->commands = commands;
}

vector<Expression*> ConditionParser:: createExpressions(vector<string> boolExp) {
    ShuntingYard s;
    vector<Expression*> v;
    Expression *leftExp, *rightExp;
    if (SymbolsTable::getInstance()->isSymbolExist(boolExp[0])) {
        leftExp = new Var(boolExp[0]);
    } else {
        leftExp = new Num(s.evaluate(boolExp[0]).evaluate());
    }

    if (SymbolsTable::getInstance()->isSymbolExist(boolExp[2])) {
        rightExp = new Var(boolExp[2]);
    } else {
        rightExp = new Num(s.evaluate(boolExp[2]).evaluate());
    }
    v.push_back(leftExp);
    v.push_back(rightExp);
    return v;
}

BooleanExpression* ConditionParser:: createCondition(vector<string> boolExp) {
    vector<Expression*> exps = createExpressions(boolExp);
    if (boolExp[1] == ">") {
        return new Greater(exps[0], exps[1]);
    } else if (boolExp[1] == ">=") {
        return new GreaterEqual(exps[0], exps[1]);
    } else if (boolExp[1] == "<") {
        return new Smaller(exps[0], exps[1]);
    } else if (boolExp[1] == "<=") {
        return  new SmallerEqual(exps[0], exps[1]);
    } else if (boolExp[1] == "==") {
        return  new Equal(exps[0], exps[1]);
    } else if (boolExp[1] == "!=") {
        return  new NotEqual(exps[0], exps[1]);
    }
}