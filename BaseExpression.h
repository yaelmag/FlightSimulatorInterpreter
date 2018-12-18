//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_BASEEXPRESSION_H
#define PROJECT1_BASEEXPRESSION_H

#include "map"
#include "string"
#include "Expression.h"

using namespace std;

class BaseExpression {

public:
    /**
     * A convenience method. Like the `evaluate(assignment)` method above,
     * but uses an empty assignment.
     * @return an empty map of assignment
     * @throws Exception - because the map of assignment is empty
     */
    virtual double evaluate() {
            map<string, double> a = &(new map<string, double>());
            return this.evaluate(a);
    }

    /**
     * Evaluate the expression using the variable values provided
     * in the assignment, and return the result.  If the expression
     * contains a variable which is not in the assignment, an exception is thrown.
     *
     * @param assignment - a map that create a mapping from keys to values, from string to double.
     * @return - the result of the expression
     * @throws Exception - if the expression contains a variable which is not in the assignment.
     */
    virtual double evaluate(map<string, double> assignment) = 0;

    /**
     * check if the expression is a number.
     * if he is a number return his value, else return null.
     * @return if the expression is a number return his value, else return null.
     */
    virtual Expression simplify() {
        try {
            return new Num(this.evaluate());
        } catch (...) {
            return NULL;
        }
    }
}



#endif //PROJECT1_BASEEXPRESSION_H
