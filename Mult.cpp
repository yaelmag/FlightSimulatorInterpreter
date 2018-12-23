//
// Created by yael on 12/18/18.
//

#include "Mult.h"

double Mult::evaluate() {
    return this->leftE.evaluate() * this->rightE.evaluate();
}

string Mult::toString() {
    return BinaryExpression::toString();
}