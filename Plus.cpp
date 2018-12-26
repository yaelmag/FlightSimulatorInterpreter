//
// Created by yael on 12/18/18.
//

#include "Plus.h"

double Plus::evaluate() {
    return this->leftE->evaluate() + this->rightE->evaluate();
}

string Plus::toString() {
    return BinaryExpression::toString();
}

