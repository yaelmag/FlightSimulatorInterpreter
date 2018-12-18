//
// Created by yael on 12/18/18.
//

#include "Plus.h"

Plus::Plus(Expression &leftE, Expression &rightE) : left(leftE), right(rightE){
    this->left = leftE;
    this->right = rightE;
}

double Plus::evaluate() {
    return this->left.evaluate() + this->right.evaluate();
}

string Plus::toString() {
    BinaryExpression::toString();
}

