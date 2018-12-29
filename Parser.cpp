//
// Created by adi on 17/12/18.
//

#include "Parser.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "SymbolsTable.h"
#include "Client.h"

Parser::Parser(/*CommandsMap &commands*/) {
    OpenServerCommand* openDataServer = new OpenServerCommand();
    commands.insert(pair<string, Command*>("openDataServer", openDataServer));
    ConnectCommand* connect = new ConnectCommand();
    commands.insert(pair<string, Command*>("connect", connect));
    DefineVarCommand* var = new DefineVarCommand();
    commands.insert(pair<string, Command*>("var", var));
    EqualOperatorCommand* equal = new EqualOperatorCommand();
    commands.insert(pair<string, Command*>("=", equal));
    PrintCommand* print = new PrintCommand();
    commands.insert(pair<string, Command*>("print", print));
    SleepCommand* sleep = new SleepCommand();
    commands.insert(pair<string, Command*>("sleep", sleep));
}

Parser *Parser:: instance = nullptr;

Parser *Parser:: getInstance() {
    if (instance == nullptr) {
        //CommandsMap commands = CommandsMap();
        instance = new Parser(/*commands*/);
    }
    return instance;
}

int Parser:: runner(vector<string> info, int index) {
    while (index < info.size() - 2) {
        cout<<"command: "<< info[index]<<endl;
        cout<<"after: "<< info[index + 1]<<endl;

        Command* c;
        if (commands.count(info[index]) == 1) {
            c = commands.find(info[index])->second;
            if (commands.find(info[index])->first == "connect") {
                cin.ignore();

                cout<<"can connect"<<endl;
            }
            index += c->doCommand(info, index + 1) + 1;
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
                this->ifWhileCommands.push_back(c);
                index = c->doCommand(info, index);
              // if its if command
            } else if (conditionType == "if") {
                c = new IfCommand(boolExp);
                this->ifWhileCommands.push_back(c);
                index = c->doCommand(info, index);
            }

          // if we get to the end of WhileLoop/If
        } else if (info[index] == "}") {
            return index;
           // if we get to EqualCommand
        } else if (info[index + 1] == "=") {
            c = commands.find(info[index + 1])->second;
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


void Parser::destroyParser() {
    if (instance != nullptr) {
        delete instance;
    }
    instance = nullptr;
}


Parser::~Parser() {
    for (auto const& command : this->commands) {
        delete(command.second);
    }
    for (auto const& ifWhile : this->ifWhileCommands) {
        delete(ifWhile);
    }

}