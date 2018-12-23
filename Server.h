//
// Created by yael on 12/20/18.
//

#ifndef PROJECT1_SERVER_H
#define PROJECT1_SERVER_H

#define BUFFER_SIZE 1024

class Server {
    int cliSockfd;
    int serverSockfd, port;
public:
    Server(int port);

    void setPort(int p);

    void openSock();

    static void readData(int cliSock);

    int getCliSock();
};

#endif //PROJECT1_SERVER_H
