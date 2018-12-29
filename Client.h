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
    static Client* instance;
    int sockfd, port;
    string ipByName;

    Client() = default;
public:
    static Client *getInstance();
    static void destroyClient();

    void setPort(int port);
    void setIp(string ipByName);
    void openSocket();
    void writeData(std::string massege, double value);
    void closeSocket();
    ~Client();
};


#endif //PROJECT1_CLIENT_H