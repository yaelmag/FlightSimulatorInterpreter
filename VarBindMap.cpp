//
// Created by adi on 18/12/18.
//

#include "VarBindMap.h"

VarBindMap:: VarBindMap() = default;

/**
 * get the var-bind map
 * @return the var-bind map
 */
map<string, string> VarBindMap:: getMap() {
    return this->varBindMap;
}

/**
 * add new var to the var-bind map
 * @param varName - the name of the new var
 * @param varValue - the bind of the new var
 */
void VarBindMap:: addVarBind(string varName, string varBind) {
    varBindMap[varName] = varBind;
}

/**
 * get the bind of specific var from the var-bind map
 * @param varName - the name of the var we want to get his value
 * @return the value of specific var from the symbol table
 */
string VarBindMap:: getVarBind(string varName) {
    if (this->varBindMap.count(varName) == 0) {
        __throw_invalid_argument("The var doesn't exist in the map");
    }
    return this->varBindMap.find(varName)->second;
}