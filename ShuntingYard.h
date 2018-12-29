//
// Created by yael on 12/19/18.
//

#ifndef PROJECT1_SHUNTINGYARD_H
#define PROJECT1_SHUNTINGYARD_H

#include <iostream>
#include "stdio.h"
#include "stack"
#include "Expression.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "Num.h"

class ShuntingYard {
    Expression* exp;
public:
    int precedence(char op);
    double applyOp(double a, double b, char op);
    Expression* evaluate(string tokens);
    ~ShuntingYard();
};

#endif //PROJECT1_SHUNTINGYARD_H
