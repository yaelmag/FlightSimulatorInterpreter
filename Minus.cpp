//
// Created by yael on 12/18/18.
//

#include "Minus.h"

double Minus::evaluate() {
    return this->leftE->evaluate() - this->rightE->evaluate();
}

string Minus::toString() {
    return BinaryExpression::toString();
}