#include <unistd.h>
#include "SymbolTable.h"
#include "VarBindMap.h"
#include "OpenServerCommand.h"
#include "iostream"
#include "BooleanExpression.h"
#include "Greater.h"
#include "Client.h"

int main() {
    Client(5402, "10.0.2.2").writeData("controls/flight/rudder", 1);
//    SymbolTable symbolTable;
//    symbolTable.getMap().insert(pair<string, double>("x", 5.0));
//    VarBindMap varBindMap;
//    varBindMap.getMap().insert(pair<string, string>("x", "/instrumentation/airspeed-indicator/indicated-speed-kt"));
//    int i;
//    vector<string> vec;
//    vec.push_back("5400");
//    vec.push_back("10");
//    vec.push_back("\n");
//    OpenServerCommand openServerCommand = OpenServerCommand(symbolTable, varBindMap);
//    openServerCommand.doCommand(vec, 0);
//    //cout << i << endl;
//    sleep(60);
//    return 0;
}