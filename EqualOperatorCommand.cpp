//
// Created by adi on 18/12/18.
//

#include "EqualOperatorCommand.h"

EqualOperatorCommand::EqualOperatorCommand(SymbolTable &varsMap, VarBindMap &varBindMap) {
    this->varsMap = varsMap;
    this->varBindMap = varBindMap;
}

int EqualOperatorCommand:: doCommand(vector<string> info, int index) {
    int count = 0;

    // if the var doesn't exist
    if (varsMap.getMap().count(info[index]) == 0) {
        __throw_invalid_argument("The var doesn't exist in the map");
    }

    // if the var has bind, connect him to the simulator
    if (info[index + 2] == "bind" && info[index + 4] == "\n") {
        if (info[index + 3][0] == '"') {
            // update the bind of the var in the varBindMap
            this->varBindMap.addVarBind(info[index], info[index + 3]);
        } else {
            string bind = this->varBindMap.getVarBind(info[index + 3]);
            // update the bind of the var in the varBindMap
            this->varBindMap.addVarBind(info[index], bind);
        }

        //todo
        //להכניס ממש את הערך שיש בסימולטור לתוך הסימבול טייבל
        count = 5;
    } else if (info[index + 2] != "bind"){

        // if there is one argument after the "="
        if (info[index + 3] == "\n") {
            double value;
            // if the argument is var, take his value from the SymbolTable map
            if (varsMap.getMap().count(info[index + 3]) != 0) {
                value = varsMap.getVarValue(info[index + 2]);
            } else {
                value = stod(info[index + 2]);
            }
            // if the var before the "=" is connected to the simulator,
            // sent to the simulator the new value
            if (this->varBindMap.getMap().count(info[index]) == 1) {
                //todo
                //לעדכן את הסימולטור עם הערך החדש
            }
            // update the other var with this new value (in the SymbolTable map)
            varsMap.setVarValue(info[index],value);
            count = 4;
          // if the argument is expression
        } else {
            string exp = "";
            string s = "";
            int i = 2;
            count = 2;
            while (info[index + i] != "\n") {
                s += info[index + i];
                i++;
                count++;
            }
            count++;
        }
    }
    return count;
}

VarBindMap EqualOperatorCommand:: getVarBindMap() {
    return this->varBindMap;
}