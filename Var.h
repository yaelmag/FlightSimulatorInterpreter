//
// Created by adi on 24/12/18.
//

#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H
#include "Expression.h"
#include "SymbolsTable.h"

class Var : public Expression{
string var;

public:

    /**
     * Constructor.
     * @param var - a var of type string
     */
    Var(string var) {
        this->var = var;
    }

    /**
     * A convenience method. Like the `evaluate(assignment)` method above,
     * but uses an empty assignment.
     * @return this var.
     * @throws Exception - nothing
     */
    double evaluate() {
        return SymbolsTable::getInstance()->getSymbolValue(var);
    }

    /**
     * Returns a nice string representation of the expression.
     * @return a nice string representation of the expression
     */
    string toString() {
        return to_string(evaluate());
    }
};


#endif //PROJECT1_VAR_H
