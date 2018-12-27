//
// Created by adi on 23/12/18.
//

#include "CheckExpressions.h"
#include "SymbolsTable.h"

CheckExpressions:: CheckExpressions() = default;
vector<string> CheckExpressions:: getExpressions(vector<string> info, int index) {
    vector<string> expressions;
    string exp = "";
    string num = "";
    int flag = 0;
    int i = 0;
    if (info[index] == "-") {
        flag = 1;
    }
    while (info[index + i] != "\n") {
        // if there is a number
        if ((info[index + i] != "=") && (info[index + i] != "+") && (info[index + i] != "-") &&
            (info[index + i] != "/") && (info[index + i] != "*") && (info[index + i] != "(") &&
            (info[index + i] != ")")) {

            if (info[index + i] != ",") {
                num = getNumber(info[index + i]);
            }

            // before the number was operator
            if(flag == 0) {
                if (i != 0 && info[index + i - 1] == ")") {
                    expressions.push_back(exp);
                    exp = "";
                    exp += num;
                    flag = 1;
                } else if (info[index + i] == ",") {
                    expressions.push_back(exp);
                    exp = "";
                } else {
                    exp += num;
                    flag = 1;
                }
                // before the number was number
            } else if (flag == 1) {
                if (info[index + i] == ",") {
                    expressions.push_back(exp);
                    exp = "";
                    flag = 0;
                } else {
                    expressions.push_back(exp);
                    exp = "";
                    exp += num;
                }
            }
            // if there is an operator
        } else {
            // before the operator was number
            if (flag == 1) {
                if (info[index + i] == "(") {
                    __throw_invalid_argument("The expression is invalid");
                }
                exp += info[index + i];
                flag = 0;
                // before the operator was operator
            } else if (flag == 0 && (checkOperator(info[index + i - 1], info[index + i]) ||
                       info[index + i - 1] == ",")) {
                cout<<"good"<<endl;
                exp += info[index + i];
                // the expression is invalid
            } else {
                __throw_invalid_argument("The expression is invalid");
            }
        }
        i++;
    }
    // if the expression ends with ')' or a number he is correct
    if ((info[index + i - 1] != "=") && (info[index + i - 1] != "+") &&
        (info[index + i - 1] != "-") && (info[index + i - 1] != "/") &&
        (info[index + i - 1] != "*") && (info[index + i - 1] != "(")) {
        if (exp != "") {
            expressions.push_back(exp);
        }
        // the expression is invalid
    } else {
        __throw_invalid_argument("The expression is invalid");
    }

    // return all the expressions
    return expressions;
}

string CheckExpressions:: getNumber(string num) {
    if (SymbolsTable::getInstance()->isSymbolExist(num)) {
        return to_string(SymbolsTable::getInstance()->getSymbolValue(num));
    }
    return num;
}

/**
 * check if the two operators can be one after the other
 * @param s1 - first operator
 * @param s2 - second operator
 * @return true if the two operators can be one after the other, else false
 */
bool CheckExpressions:: checkOperator(string s1, string s2) {
    if (s1 == "(") {
        if (s2 == "(" || s2 == "-") {
            return true;
        }
    } else if (s2 == "-") {
        if (s1 == "*" || s1 == "/") {
            return true;
        }
    } else if ((s2 == "(") || (s1 == ")")) {
        return true;
    }
    return false;
}

int CheckExpressions:: getExpressionLength(string exp) {
    int count = 0;
    bool flag = false;
    for (int i = 0; i < exp.length(); i++) {
        if ((exp[i] != '+') && (exp[i] != '-') && (exp[i] != '/') &&
            (exp[i] != '*') && (exp[i] != '(') && (exp[i] != ')')) {
            if (!flag) {
                count++;
                flag = true;
            }
        } else {
            count++;
            flag = false;
        }
    }
    return count;

}

int CheckExpressions:: countCommas(vector<string> info, int index) {
    int count = 0;
    int i = 0;
    while (info[index + i] != "\n") {
        if (info[index + i] == ",") {
            count++;
        }
        i++;
    }
    return count;
}