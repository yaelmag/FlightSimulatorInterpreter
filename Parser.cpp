//
// Created by adi on 17/12/18.
//

#include "Parser.h"
#include "WhileCommand.h"
#include "IfCommand.h"
extern bool isConnect;

Parser::Parser(CommandsMap &commands) {
    this->commands = commands;
}

Parser *Parser::instance = nullptr;

Parser *Parser::getInstance() {
    if (instance == nullptr) {
        CommandsMap commands = CommandsMap();
        instance = new Parser(commands);
    }
    return instance;
}

int Parser:: runner(vector<string> info, int index) {
    while (index < info.size() - 2) {
        cout<<"command:"<<info[index]<<endl;
        cout<<"after:"<<info[index + 1]<<endl;

        Command* c = commands.getMap().find(info[index])->second;
        if (commands.getMap().count(info[index]) == 1) {
            if (commands.getMap().find(info[index])->first == "connect") {
                cout<<"beforeLoop"<<endl;
                while(!isConnect) {
                    continue;
                }
                cout<<"afterLoop"<<endl;
                cin.ignore();
                cout<<"can connect"<<endl;
            }
            cout<<"index:"<<index<<endl;
            index += c->doCommand(info, index + 1) + 1;
            cout<<"index:"<<index<<endl;
          // if there is while or if
        } else if (info[index] == "while" || info[index] == "if") {
            string conditionType = info[index];
            vector<string> boolExp;
            string word = "";
            // represent if we already see the boolOperator
            bool flag = false;
            // get on to the condition
            index++;
            while (info[index] != "{") {
                // we still doesn't see the boolOperator
                if (!isBoolOperator(info[index]) && !flag) {
                    word += info[index];
                  // if we see the boolOperator
                } else if (isBoolOperator(info[index])) {
                    boolExp.push_back(word);
                    boolExp.push_back(info[index]);
                    word = "";
                    flag = true;
                  // we already saw the boolOperator
                } else if (!isBoolOperator(info[index]) && flag) {
                    word += info[index];
                }
                index++;
            }
            boolExp.push_back(word);
            // go on the commands in the while loop/ if
            index += 2;

            // if its while command
            if (conditionType == "while") {
                c = new WhileCommand(boolExp);
                index = c->doCommand(info, index);
              // if its if command
            } else if (conditionType == "if") {
                c = new IfCommand(boolExp);
                index = c->doCommand(info, index);
            }
          // if we get to the end of WhileLoop/If
        } else if (info[index] == "}") {
            return index;
           // if we get to EqualCommand
        } else if (info[index + 1] == "=") {
            cout<<"yayy"<<endl;
            c = commands.getMap().find(info[index + 1])->second;
            index += c->doCommand(info, index + 2) + 2;
        }
    }
    return 0;
}

bool Parser:: isBoolOperator(string boolOperator) {
    if ((boolOperator == ">") || (boolOperator == ">=") || (boolOperator == "<") ||
        (boolOperator == "<=") || (boolOperator == "==") || (boolOperator == "!=")) {
        return true;
    }
    return false;
}