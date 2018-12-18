//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_SYMBOLTABLE_H
#define PROJECT1_SYMBOLTABLE_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class SymbolTable {
map<string, double> symbolTable;

public:
    SymbolTable();
    map<string, double> getMap();
    void addVar(string varName, double varValue);
    double getVarValue(string varName);
};


#endif //PROJECT1_SYMBOLTABLE_H
