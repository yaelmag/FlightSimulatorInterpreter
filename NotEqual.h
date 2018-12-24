//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_NOTEQUAL_H
#define PROJECT1_NOTEQUAL_H

#include "BooleanExpression.h"

class NotEqual : public BooleanExpression {
public:
    NotEqual(Expression& leftExp, Expression& rightExp) : BooleanExpression(leftExp, rightExp) {
    }

    string toString() override;

    double evaluate() override;
};

#endif //PROJECT1_NOTEQUAL_H
