//
// Created by adi on 18/12/18.
//

#include "SymbolTable.h"

SymbolTable:: SymbolTable() = default;

/**
 * get the symbol table map
 * @return the symbol table
 */
map<string, double> SymbolTable:: getMap() {
    return this->symbolTable;
}

/**
 * add new var to the symbol table
 * @param varName - the name of the new var
 * @param varValue - the value of the new var
 */
void SymbolTable:: addVar(string varName, double varValue) {
    symbolTable[varName] = varValue;
}

void SymbolTable:: setVarValue(string varName, double varValue) {
    symbolTable[varName] = varValue;
}

/**
 * get the value of specific var from the symbol table
 * @param varName - the name of the var we want to get his value
 * @return the value of specific var from the symbol table
 */
double SymbolTable:: getVarValue(string varName) {
    if (this->symbolTable.count(varName) == 0) {
        __throw_invalid_argument("The var doesn't exist in the map");
    }
    return this->symbolTable.find(varName)->second;
}