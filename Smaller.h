//
// Created by yael on 12/23/18.
//

#ifndef PROJECT1_SMALLER_H
#define PROJECT1_SMALLER_H

#include "BooleanExpression.h"

class Smaller : public BooleanExpression {
public:
    Smaller(Expression* leftExp, Expression* rightExp) : BooleanExpression(leftExp, rightExp) {
    }

    string toString() override;

    double evaluate() override;
};


#endif //PROJECT1_SMALLER_H
