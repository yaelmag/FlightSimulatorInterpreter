//
// Created by adi on 17/12/18.
//

#include "OpenServerCommand.h"

OpenServerCommand:: OpenServerCommand(SymbolTable* varsMap, VarBindMap* varBindMap) {
    this->varsMap = varsMap;
    this->varBindMap = varBindMap;
}

int OpenServerCommand:: doCommand(vector<string> info, int index) {

}