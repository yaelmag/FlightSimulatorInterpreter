//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_GREATER_H
#define PROJECT1_GREATER_H

#include "BooleanExpression.h"

class Greater : public BooleanExpression {
public:
    Greater(Expression& leftExp, Expression& rightExp) : BooleanExpression(leftExp, rightExp) {
    }

    string toString() override;


    double evaluate() override;
};


#endif //PROJECT1_GREATER_H
