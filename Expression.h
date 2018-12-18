//
// Created by yael on 12/18/18.
//

#ifndef PROJECT1_EXPRESSION_H
#define PROJECT1_EXPRESSION_H

#include <map>
#include <list>

using namespace std;

class Expression {
public:
    virtual double evaluate(map<string, double> assignment) = 0;
    virtual double evaluate() = 0;
    virtual string toString() = 0;
};

#endif //PROJECT1_EXPRESSION_H
