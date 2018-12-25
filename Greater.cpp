//
// Created by yael on 12/23/18.
//

#include "Greater.h"

string Greater::toString() {
    return leftE->toString() + ">" + rightE->toString();
}

double Greater::evaluate() {
    return (leftE->evaluate() > rightE->evaluate());
}