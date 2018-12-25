//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_EQUAL_H
#define PROJECT1_EQUAL_H


#include "BooleanExpression.h"

class Equal : public BooleanExpression {
public:
    Equal(Expression* leftExp, Expression* rightExp) : BooleanExpression(leftExp, rightExp) {
    }

    string toString() override;

    double evaluate() override;
};


#endif //PROJECT1_EQUAL_H
