//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_BINARYEXPRESSION_H
#define PROJECT1_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression &leftE;
    Expression &rightE;

public:
    BinaryExpression(Expression &left, Expression &right) : leftE(left), rightE(right) {
        this->leftE = left;
        this->rightE = right;
    }
    virtual string toString() {
        return to_string(this->evaluate());
    }

};

#endif //PROJECT1_BINARYEXPRESSION_H
