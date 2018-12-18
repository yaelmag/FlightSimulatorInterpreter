//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_MINUS_H
#define PROJECT1_MINUS_H

#include "BinaryExpression.h"

class Minus : BinaryExpression{
    Expression& left;
    Expression& right;

public:
    Minus(Expression &leftE, Expression &rightE);

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_MINUS_H
