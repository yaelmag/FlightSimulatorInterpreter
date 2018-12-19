//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_MULT_H
#define PROJECT1_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression{
public:
    Mult(Expression &leftE, Expression &rightE) : BinaryExpression(leftE, rightE) {
        this->leftE = leftE;
        this->rightE = rightE;
    }

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_MULT_H
