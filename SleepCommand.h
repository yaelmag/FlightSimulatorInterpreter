//
// Created by adi on 22/12/18.
//

#ifndef PROJECT1_SLEEPCOMMAND_H
#define PROJECT1_SLEEPCOMMAND_H
#include "Command.h"
#include "SymbolTable.h"

class SleepCommand : public Command {
public:
    SleepCommand();
    int doCommand(vector<string> info, int index);

};


#endif //PROJECT1_SLEEPCOMMAND_H
