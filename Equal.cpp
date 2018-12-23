//
// Created by yael on 12/23/18.
//

#include "Equal.h"


string Equal::toString() {
    return leftE.toString() + "==" + rightE.toString();
}

double Equal::evaluate() {
    return (leftE.evaluate() == rightE.evaluate());
}