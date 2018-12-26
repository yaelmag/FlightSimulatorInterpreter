//
// Created by adi on 24/12/18.
//

#ifndef PROJECT1_WHILECOMMAND_H
#define PROJECT1_WHILECOMMAND_H

#include "ConditionParser.h"

class WhileCommand : public ConditionParser {
public:
    WhileCommand(vector<string> boolExp);
    int doCommand(vector<string> info, int index);


};


#endif //PROJECT1_WHILECOMMAND_H
