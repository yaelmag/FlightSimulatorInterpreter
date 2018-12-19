//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_PLUS_H
#define PROJECT1_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{

public:
    Plus(Expression &leftE, Expression &rightE) : BinaryExpression(leftE, rightE) {
        this->leftE = leftE;
        this->rightE = rightE;
    }

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_PLUS_H
