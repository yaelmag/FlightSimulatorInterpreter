//
// Created by adi on 18/12/18.
//

#include "CommandExpression.h"

CommandExpression:: CommandExpression(Command *command) {
    this->command = command;
}

void CommandExpression:: calculate(vector<string> info) {
    this->command->doCommand(info);
}