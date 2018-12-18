//
// Created by yael on 12/18/18.
//

#include "Minus.h"

Minus::Minus(Expression &leftE, Expression &rightE) : left(leftE), right(rightE) {
    this->left = leftE;
    this->right = rightE;
}

double Minus::evaluate() {
    return this->left.evaluate() - this->right.evaluate();
}

string Minus::toString() {
    BinaryExpression::toString();
}