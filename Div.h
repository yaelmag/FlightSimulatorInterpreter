//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_DIV_H
#define PROJECT1_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression *leftE, Expression *rightE) : BinaryExpression(leftE, rightE) {
        if (rightE->toString().substr(0, 2).compare("0.") == 0) {
            throw "divide by zero exception";
        }
        this->leftE = leftE;
        this->rightE = rightE;
    }

    double evaluate() override;

    string toString() override;
};


#endif //PROJECT1_DIV_H
