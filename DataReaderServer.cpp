//
// Created by adi on 19/12/18.
//
#include "iostream"
#include "DataReaderServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>

using namespace std;

DataReaderServer::DataReaderServer(int port, SymbolTable* symbolTable, VarBindMap* bindMap) {
    this->port = port;
    this->symbolTable = symbolTable;
    this->bindMap = bindMap;
    server = new Server(port);
}

void DataReaderServer::readFromClient() {
    this->server->setPort(this->port);
    server->openSock();
     thread t (server->readData, server->getCliSock(), symbolTable, bindMap);
    t.detach();
}

void DataReaderServer::setPort(int p) {
    cout << p << endl;
    this->port = p;
    cout << this->port << endl;
}