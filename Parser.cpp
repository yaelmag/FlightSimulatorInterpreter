//
// Created by adi on 17/12/18.
//

#include "Parser.h"

Parser::Parser(CommandsMap &commands) {
    this->commands = commands;
}

void Parser:: parser(vector<string> info) {
    int index = 0;
    while (index < info.size() - 2) {
        Command* c = commands.getMap().find(info[index])->second;
        if (c != nullptr) {
            index += c->doCommand(info, index + 1);
        } else if (info[index] == "while") {
            //c = Loop
        } else if (info[index + 1] == "=") {
            c = commands.getMap().find(info[index + 1])->second;
            index += c->doCommand(info, index);
        }
    }

}