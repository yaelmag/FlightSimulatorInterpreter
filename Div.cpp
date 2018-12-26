//
// Created by yael on 12/18/18.
//

#include "Div.h"

double Div::evaluate() {
    return this->leftE->evaluate() / this->rightE->evaluate();
}

string Div::toString() {
    return BinaryExpression::toString();
}