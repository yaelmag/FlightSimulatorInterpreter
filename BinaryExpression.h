//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_BINARYEXPRESSION_H
#define PROJECT1_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {

public:
    virtual double evaluate() override = 0;
    virtual string toString() {
        return to_string(this->evaluate());
    }

};

#endif //PROJECT1_BINARYEXPRESSION_H
