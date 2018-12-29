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

DataReaderServer::DataReaderServer(int port){
    this->port = port;
}

void DataReaderServer::readFromClient() {
    Server::getInstance()->setPort(this->port);
    Server::getInstance()->openSock();
    //server->readLineBeforeStart(server->getCliSock());
    thread t (Server::getInstance()->readData, Server::getInstance()->getCliSock());
    t.detach();
}

void DataReaderServer::setPort(int p) {
    //cout << p << endl;
    this->port = p;
    //cout << this->port << endl;
}

/*
DataReaderServer:: ~DataReaderServer() {
    if (this->server != nullptr) {
        this->server->closeSocket();
        delete(server);
    }
}*/
