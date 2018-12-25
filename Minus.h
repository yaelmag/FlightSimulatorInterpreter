//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_MINUS_H
#define PROJECT1_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{

public:
    Minus(Expression *leftE, Expression *rightE) : BinaryExpression(leftE, rightE) {
        this->leftE = leftE;
        this->rightE = rightE;
    }

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_MINUS_H
