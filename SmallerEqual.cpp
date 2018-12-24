//
// Created by yael on 12/23/18.
//

#include "SmallerEqual.h"

string SmallerEqual::toString() {
    return (leftE->toString() + "<=" + rightE->toString());
}

double SmallerEqual::evaluate() {
    return (leftE->evaluate() <= rightE->evaluate());
}