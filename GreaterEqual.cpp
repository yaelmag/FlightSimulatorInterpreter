//
// Created by yael on 12/23/18.
//

#include "GreaterEqual.h"

string GreaterEqual::toString() {
    return (leftE.toString() + ">=" + rightE.toString());
}

double GreaterEqual::evaluate() {
    return (leftE.evaluate() >= rightE.evaluate());
}