//
// Created by yael on 12/18/18.
//
#include "Expression.h"
#include "map"
#include "list"

class Num : public Expression {
    double num;

public:
/**
 * Constructor.
 * @param num - a number of type double
 */
    Num(double num) {
        this->num = num;
    }

/**
 * A convenience method. Like the `evaluate(assignment)` method above,
 * but uses an empty assignment.
 * @return this number.
 * @throws Exception - nothing
 */
    double evaluate() {
        return this->num;
    }

/**
 * Returns a nice string representation of the expression.
 * @return a nice string representation of the expression
 */
    string toString() {
        return to_string(this->num);
    }
};