//
// Created by adi on 18/12/18.
//

#ifndef PROJECT1_BINDMAP_H
#define PROJECT1_BINDMAP_H
#include <string>
#include <vector>
#include <map>

using namespace std;

class VarBindMap {
map<string, string> varBindMap;

public:
    VarBindMap();
    map<string, string> getMap();
    void addVarBind(string varName, string varBind);
    string getVarBind(string varName);
};


#endif //PROJECT1_BINDMAP_H
