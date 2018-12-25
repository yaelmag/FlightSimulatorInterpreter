//
// Created by adi on 25/12/18.
//

#ifndef PROJECT1_IFLOOP_H
#define PROJECT1_IFLOOP_H

#include "ConditionParser.h"

class IfCommand : public ConditionParser{
public:
    IfCommand(vector<string> boolExp);
    int doCommand(vector<string> info, int index);
};

#endif //PROJECT1_IFLOOP_H
