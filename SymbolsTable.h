//
// Created by adi on 24/12/18.
//

#ifndef PROJECT1_SYMBOLSTABLE_H
#define PROJECT1_SYMBOLSTABLE_H



#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <mutex>
//#include "DataWriterClient.h"

using namespace std;

struct SymbolData
{
    double value;
    std::string path;

    SymbolData(double value, std::string path = nullptr){
        this->value = value;
        this->path = path;
    }
};

class SymbolsTable {

private:
    /* Here will be the instance stored. */
    static SymbolsTable *instance;

    /* Private constructor to prevent instancing. */
    SymbolsTable();

    std::map<std::string, SymbolData*> symbolsMap;
    // DataWriterClient *client;

    mutex mtx1; //lock for symbols sets
    mutex mtx2; //lock for symbols sets
    mutex mtx3; //lock for symbols sets
    mutex mtx4; //lock for symbols sets

public:
    /* Static access method. */
    static SymbolsTable *getInstance();
    static void destroyInstance();

    //static std::string paths[23];
    static std::vector<std::string> paths;

    void setSymbol(std::string symbol, double value, std::string path);
    void setSymbol(std::string symbol, std::string path);
    void setSymbol(std::string symbol, double value);
    double getSymbolValue(std::string symbol);
    string getSymbolPath(std::string symbol);
    void bindNewSymbolToExistSymbol(std::string newSymbol, std::string existSymbol);
    void printSymbols();
    bool isSymbolExist(std::string symbol);

    //DataWriterClient *getClient() const;

    //void setClient(DataWriterClient *client);
    ~SymbolsTable();
};


#endif //PROJECT1_SYMBOLSTABLE_H
