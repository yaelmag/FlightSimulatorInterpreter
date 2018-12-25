//
// Created by yael on 12/23/18.
//

#include "Smaller.h"

string Smaller::toString() {
    return leftE->toString() + "<" + rightE->toString();
}

double Smaller::evaluate() {
    return (leftE->evaluate() < rightE->evaluate());
}