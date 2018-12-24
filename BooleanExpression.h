//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_BOOLEANEXPRESSION_H
#define PROJECT1_BOOLEANEXPRESSION_H

#include "BinaryExpression.h"

class BooleanExpression : public BinaryExpression {

public:
    BooleanExpression(Expression *left, Expression *right);

    void setLeft(Expression *left);
    void setRight(Expression *right);

    virtual string toString() override = 0;

    virtual double evaluate() override = 0;
};


#endif //PROJECT1_BOOLEANEXPRESSION_H
