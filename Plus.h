//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_PLUS_H
#define PROJECT1_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
    Expression& left;
    Expression& right;

public:
    Plus(Expression &leftE, Expression &rightE);

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_PLUS_H
