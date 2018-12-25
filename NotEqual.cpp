//
// Created by yael on 12/23/18.
//

#include "NotEqual.h"

string NotEqual::toString() {
    return leftE->toString() + "!=" + rightE->toString();
}

double NotEqual::evaluate() {
    return (leftE->evaluate() != rightE->evaluate());
}