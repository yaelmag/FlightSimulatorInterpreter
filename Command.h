//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command {

public:
    virtual void doCommand(vector<string>) = 0;
};
#endif //PROJECT1_COMMAND_H
