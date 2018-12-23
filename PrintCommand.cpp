//
// Created by adi on 20/12/18.
//

#include "PrintCommand.h"
#include <iostream>

PrintCommand:: PrintCommand(SymbolTable &varsMap) {
    this->varsMap = varsMap;
}

int PrintCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    if (info[index + 1] == "\n") {
        count = 3;
        double value;
        // if the var in the map
        if (varsMap.getMap().count(info[index]) != 0) {
            value = varsMap.getVarValue(info[index]);
            cout<<value<<endl;
          // if this is a string
        } else if (info[index].at(0) == '"') {
            cout<<info[index]<<endl;
          // if this is a number
        } else {
            value = stod(info[index]);
            cout << value << endl;
        }
    } else {
        vector<string> exp = getExpressions(info, index);
        if (exp.size() != 1) {
            __throw_invalid_argument("There are too many arguments");
        }
        count = 2 + exp[0].length();
        //todo
        //לקרוא למה שיעלי עשתה כדי לפרש את הביטוי
        double num = 0;
        cout<<num<<endl;
    }
    return count;
}

vector<string> PrintCommand:: getExpressions(vector<string> info, int index) {
    vector<string> expressions;
    string exp = "";
    string num;
    int flag = 0;
    int i = 0;
    while (info[index + i] != "\n") {
        // if there is a number
        if ((info[index + i] != "=") && (info[index + i] != "+") && (info[index + i] != "-") &&
            (info[index + i] != "/") && (info[index + i] != "*") && (info[index + i] != "(") &&
            (info[index + i] != ")")) {

            num = getNumber(varsMap, info[index + i]);
            // before the number was operator
            if (flag == 0) {
                if (info[index + i - 1] == ")") {
                    expressions.push_back(exp);
                    exp = "";
                    exp += num;
                } else {
                    exp += num;
                }
                flag = 1;
                // before the number was number
            } else if (flag == 1){
                expressions.push_back(exp);
                exp = "";
                exp += num;
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
            } else if (flag == 0 && checkOperator(info[index + i - 1], info[index + i])){
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

string PrintCommand:: getNumber(SymbolTable map, string num) {
    if (map.getMap().count(num) == 1) {
        return to_string(map.getVarValue(num));
    }
    return num;
}

/**
 * check if the two operators can be one after the other
 * @param s1 - first operator
 * @param s2 - second operator
 * @return true if the two operators can be one after the other, else false
 */
bool PrintCommand:: checkOperator(string s1, string s2) {
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