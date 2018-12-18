//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_BINARYEXPRESSION_H
#define PROJECT1_BINARYEXPRESSION_H

#include "BaseExpression.h"
#include "Expression.h"

class BinaryExpression : public BaseExpression, Expression{
    Expression& leftE;
    Expression& rightE;

public:

/**
 * There is 9 constructors of the binary expressions.
 * every constructor matching to different expression.
 */

/**
 * constructor 1.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(Expression& leftE, Expression& rightE) : leftE(leftE), rightE(rightE){
        this->leftE = leftE;
        this->rightE = rightE;
    }

/**
 * constructor 2.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(Expression leftE, double rightE) : leftE(leftE), rightE(new Num(rightE)) {
        this->leftE = leftE;
        this->rightE = new Num(rightE);
    }

/**
 * constructor 3.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(Expression leftE, string rightE) : leftE(leftE), rightE(new Var(rightE)){
        this->leftE = leftE;
        this->rightE = new Var(rightE);
    }

/**
 * constructor 4.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(double leftE, Expression rightE) :  leftE(new Num(leftE)), rightE(rightE){
        this->leftE = new Num(leftE);
        this->rightE = rightE;
    }

/**
 * constructor 5.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(double leftE, string rightE) {
        this->leftE = new Num(leftE);
        this->rightE = new Var(rightE);
    }

/**
 * constructor 6.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(double leftE, double rightE) {
        this->leftE = new Num(leftE);
        this->rightE = new Num(rightE);
    }

/**
 * constructor 7.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(string leftE, string rightE) {
        this->leftE = new Var(leftE);
        this->rightE = new Var(rightE);
    }

/**
 * constructor 8.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(string leftE, Expression rightE) {
        this->leftE = new Var(leftE);
        this->rightE = rightE;
    }

/**
 * constructor 9.
 * @param leftE - the left expression
 * @param rightE - the right expression
 */
    BinaryExpression(string leftE, double rightE) {
        this->leftE = new Var(leftE);
        this->rightE = new Num(rightE);
    }

/**
 * return the left expression.
 * @return the left expression.
 */
    Expression getLeftE() {
        return this->leftE;
    }

/**
 * return the right expression.
 * @return the right expression.
 */
    Expression getRightE() {
        return this->rightE;
    }

    //TODO NULL
/**
 * Returns a list of the variables in the expression.
 * @return a list of the variables in the expression
 */
    list<string> getVariables() {
        list<string> *l = new list<string>();
        // if the list of variables of leftE is not empty
        if (this->getLeftE().getVariables() != NULL) {
            // add the variables to the new list
            l->insert(l->end(), this->getLeftE().getVariables().begin(), this->getLeftE().getVariables().end());
        }
        // if the list of variable of rightE is not empty
        if (this->getRightE().getVariables() != NULL) {
            // add the variables to the new list
            l->insert(l->end(), this->getRightE().getVariables().begin(), this->getRightE().getVariables().end());
        }
        // return the new list of the variables
        return *l;
    }
};


#endif //PROJECT1_BINARYEXPRESSION_H
