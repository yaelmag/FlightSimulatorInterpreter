//
// Created by yael on 12/24/18.
//

#ifndef PROJECT1_CLIENT_H
#define PROJECT1_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <string>

using namespace std;

class Client {
    int sockfd, port;
    char* ipByName;

public:
    Client(int port, char* ipByName);
    void writeData(string massege, double value);
};


#endif //PROJECT1_CLIENT_H
//TODO: finish the client and finish the table according the map of shaked in the server and the client.