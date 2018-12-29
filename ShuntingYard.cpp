// CPP program to evaluate a given
// expression where tokens are
// separated by space.
//#include <bits/stdc++.h>
#include "ShuntingYard.h"

using namespace std;

// Function to find precedence of
// operators.
int ShuntingYard::precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
double ShuntingYard::applyOp(double a, double b, char op){
    Expression* aExp = new Num(a);
    Expression* bExp = new Num(b);
    switch(op){
        case '+': return (Plus(aExp, bExp)).evaluate();
        case '-': return (Minus(aExp, bExp)).evaluate();
        case '*': return (Mult(aExp, bExp)).evaluate();
        case '/': return (Div(aExp, bExp)).evaluate();
    }
    return 0;
}

// Function that returns value of
// expression after evaluation.
Expression& ShuntingYard::evaluate(string tokens){
    int i;
    int opFlag = 1;

    // stack to store integer values.
    stack <double> values;

    // stack to store operators.
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++){

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
            opFlag = 1;
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i])) {
            double val = 0;
            int isFrac = 0;
            double fracion = 1;

            // There may be more than one
            // digits in number.
            while((i < tokens.length()) && ((isdigit(tokens[i])) || (tokens[i] == '.'))) {
                if (tokens[i] == '.') {
                    isFrac = 1;
                }else if (isFrac) {
                    fracion = fracion/10;
                    val = val + (fracion * (tokens[i]-'0'));
                } else {
                    val = (val*10) + (tokens[i]-'0');
                }
                i++;
            }
            i--;
            opFlag = 0;
            values.push(val);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')') {
            while(!ops.empty() && ops.top() != '(')
            {
                char op = ops.top();
                ops.pop();

                double val2 = values.top();
                values.pop();

                double val1;
                //if (ops.top() != '(') {
                    val1 = values.top();
                    values.pop();
                //} else {
                //    val1 = 0;
                //}


                values.push(applyOp(val1, val2, op));
            }

            opFlag = 1;
            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && precedence(ops.top())
                                  >= precedence(tokens[i])){
                if (tokens[i] == '-' && ops.size() >= values.size()) {
                    values.push(0);
                    break;
                }
                double val1 = 0, val2 = 0;

                char op = ops.top();
                ops.pop();

                val2 = values.top();
                values.pop();

                if (op != '-' || !values.empty()) {
                    val1 = values.top();
                    values.pop();
                }

                values.push(applyOp(val1, val2, op));
            }

            if (opFlag == 1 && tokens[i] == '-') {
                values.push(0);
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        double val2 = values.top();
        values.pop();

        double val1;
        if (values.empty()) {
            val1 = 0;
        }else {
            val1 = values.top();
            values.pop();
        }

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return *(new Num(values.top()));
}
