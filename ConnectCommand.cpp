//
// Created by adi on 18/12/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(SymbolTable* varsMap, VarBindMap* varBindMap) {
    this->varsMap = varsMap;
    this->varBindMap = varBindMap;
}

int ConnectCommand:: doCommand(vector<string> info, int index) {

}