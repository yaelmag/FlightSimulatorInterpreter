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

using namespace std;

class Parser {
map<string, Command*> commands;
vector<Command*> ifWhileCommands;
//CommandsMap commands;
static Parser *instance;
    bool isBoolOperator(string boolOperator);
public:
    static Parser *getInstance();
    static void destroyParser();

    Parser(/*CommandsMap &commands*/);
    int runner(vector<string> info, int index);
    ~Parser();
};


#endif //PROJECT1_PARSER_H
