//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_INTERPETER_H
#define PROJECT1_INTERPETER_H
#include <string>
#include <vector>
#include <map>
#include "Command.h"
using namespace std;

class Interpeter {
map<string, Command> commands;

public:
    vector<string> lexer(string info);
    void parser(vector<string> info);
};


#endif //PROJECT1_INTERPETER_H
