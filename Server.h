//
// Created by yael on 12/20/18.
//

#ifndef PROJECT1_SERVER_H
#define PROJECT1_SERVER_H

#define BUFFER_SIZE 1024

#include <vector>
#include "string"
#include "SymbolsTable.h"

using namespace std;

class Server {
    int cliSockfd;
    int serverSockfd, port;
    map<string, SymbolData*> symbolsMap = SymbolsTable::getInstance()->getSymbolsMap();

    static void updateTable(string massege);
    static int indexInMap(string path);
    static vector<double > split(string info, char divide);
public:
    Server(int port);

    void setPort(int p);

    void openSock();

    static void readData(int cliSock);

    int getCliSock();
};

#endif //PROJECT1_SERVER_H
