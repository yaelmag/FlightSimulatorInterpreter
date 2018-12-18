//
// Created by adi on 17/12/18.
//

#include "Parser.h"

Parser::Parser() {
    this->commands = CommandsMap().getMap();
    this->varsMap = SymbolTable();
}

void Parser:: parser(vector<string> info) {
    int index = 0;
    while (index < info.size() - 1) {
        Command* c = commands.find(info[index])->second;
        if (c != nullptr) {
            index += c->doCommand(info, index + 1, &varsMap);
        } else if (info[index + 1] == "=") {
            c = commands.find(info[index + 1])->second;
            index += c->doCommand(info, index, &varsMap);
        }
    }

}