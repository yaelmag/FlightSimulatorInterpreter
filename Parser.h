//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H
#include <string>
#include <vector>
#include <map>
#include "Command.h"
#include "CommandsMap.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "VarBindMap.h"

using namespace std;

class Parser {
CommandsMap commands;
static Parser *instance;
    bool isBoolOperator(string boolOperator);
public:
    static Parser *getInstance();
    Parser(CommandsMap &commands);
    int runner(vector<string> info, int index);
};


#endif //PROJECT1_PARSER_H
