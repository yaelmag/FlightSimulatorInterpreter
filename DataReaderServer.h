//
// Created by adi on 19/12/18.
//

#ifndef PROJECT1_DATAREADERSERVER_H
#define PROJECT1_DATAREADERSERVER_H

#include "SymbolTable.h"
#include "VarBindMap.h"
#include "Server.h"

class DataReaderServer {
    int port;
    Server* server;
public:
    DataReaderServer(int port);
    void readFromClient();
    void setPort(int p);
};


#endif //PROJECT1_DATAREADERSERVER_H
