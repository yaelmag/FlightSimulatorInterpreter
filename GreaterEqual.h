//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_GREATEREQUAL_H
#define PROJECT1_GREATEREQUAL_H

#include "BooleanExpression.h"

class GreaterEqual : public BooleanExpression {

public:
    GreaterEqual(Expression& leftExp, Expression& rightExp) : BooleanExpression(leftExp, rightExp) {
    }

    string toString() override;

    double evaluate() override;
};


#endif //PROJECT1_GREATEREQUAL_H
