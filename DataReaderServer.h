//
// Created by adi on 19/12/18.
//

#ifndef PROJECT1_DATAREADERSERVER_H
#define PROJECT1_DATAREADERSERVER_H

#include "Server.h"

class DataReaderServer {
    int port;
public:
    DataReaderServer(int port);
    void readFromClient();
    void setPort(int p);
    ~DataReaderServer() = default;
};


#endif //PROJECT1_DATAREADERSERVER_H
