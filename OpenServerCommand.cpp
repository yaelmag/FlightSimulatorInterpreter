//
// Created by adi on 17/12/18.
//

#include "iostream"
#include "OpenServerCommand.h"

int OpenServerCommand:: doCommand(vector<string> info, int index) {
    int arg1, arg2;
    if (info.at(2) != "\n") {
        throw "invalid number of arguments";
    }
    try {
        arg1 = stoi(info.at(0));
        arg2 = stoi(info.at(1));
    } catch (...) {
        throw "invalid type of arguments (required int)";
    }
    this->dataReaderServer.setPort(arg1);
    this->dataReaderServer.readFromClient();
    return index+3;
}