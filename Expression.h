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
    virtual double evaluate() = 0;
    virtual string toString() {
        return "default string";
    }
    virtual ~Expression() = default;
};

#endif //PROJECT1_EXPRESSION_H
