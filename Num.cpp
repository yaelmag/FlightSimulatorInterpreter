//
// Created by yael on 12/18/18.
//
#include "Expression.h"
#include "map"
#include "list"

/**
 * A class that represents an expression of Number.
 * @author Adi Yanai
 */
class Num : Expression {
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
 * Evaluate the expression using the variable values provided
 * in the assignment, and return the result.  If the expression
 * contains a variable which is not in the assignment, an exception is thrown.
 *
 * @param assignment - a map that create a mapping from keys to values, from string to double.
 * @return - the number.
 * @throws Exception - if the expression contains a variable which is not in the assignment.
 */
public

    double evaluate(Map <String, Double> assignment)

    throws Exception{
            return this.num;
    }

/**
 * A convenience method. Like the `evaluate(assignment)` method above,
 * but uses an empty assignment.
 * @return this number.
 * @throws Exception - nothing
 */
public

    double evaluate()

    throws Exception{
            return this.num;
    }

/**
 * Returns a list of the variables in the expression.
 * @return a list of the variables in the expression
 */
public

    List <String> getVariables() {
        List <String> l = new ArrayList<String>();
        return l;
    }

/**
 * Returns a nice string representation of the expression.
 * @return a nice string representation of the expression
 */
public

    String toString() {
        return Double.toString(this.num);
    }

/**
 * Returns a new expression in which all occurrences of the variable
 * var are replaced with the provided expression (Does not modify the current expression).
 * @param var - the variable we want to replace
 * @param expression - an expression that replace the variable var in all his occurrences
 * @return a new expression
 */
public

    Expression assign(String var, Expression expression) {
        return this;
    }

/**
 * Returns the expression tree resulting from differentiating
 * the current expression relative to variable var.
 * @param var - the variable that according to him we want to differentiate the expression.
 * @return the expression tree resulting from differentiating the current expression relative to variable var,
 *            because this is a number, the function always return 0.
 */
public

    Expression differentiate(String var) {
        return new Num(0);
    }

/**
 * Returned a simplified version of the current expression.
 * @return a simplified version of the current expression
 */
public

    Expression simplify() {
        return this;
    }
}