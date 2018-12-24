//
// Created by yael on 12/20/18.
//

#ifndef PROJECT1_SERVER_H
#define PROJECT1_SERVER_H

#define BUFFER_SIZE 1024

#include "string"
#include "SymbolTable.h"
#include "VarBindMap.h"

using namespace std;

class Server {
    int cliSockfd;
    int serverSockfd, port;
    //static SymbolTable symbolTable;
    //static VarBindMap bindMap;

    static void updateTable(string massege, SymbolTable* symbolTable, VarBindMap* bindMap);
    static int indexInMap(string path);
    static vector<double > split(string info, char divide);
public:
    Server(int port);

    void setPort(int p);

    void openSock();

    static void readData(int cliSock, SymbolTable* symbolTable, VarBindMap* bindMap);

    int getCliSock();
};

#endif //PROJECT1_SERVER_H
