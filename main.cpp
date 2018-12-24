#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 5402;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("10.0.2.2");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    /* Send message to the server */
    n = write(sockfd, buffer, strlen(buffer));
    n = write(sockfd, "\r\n", 2);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    return 0;
}
/*
#include <unistd.h>
#include "SymbolTable.h"
#include "VarBindMap.h"
#include "OpenServerCommand.h"
#include "iostream"
#include "BooleanExpression.h"
#include "Greater.h"

int main() {
    SymbolTable symbolTable;
    symbolTable.getMap().insert(pair<string, double>("x", 5.0));
    VarBindMap varBindMap;
    varBindMap.getMap().insert(pair<string, string>("x", "/instrumentation/airspeed-indicator/indicated-speed-kt"));
    int i;
    vector<string> vec;
    vec.push_back("5400");
    vec.push_back("10");
    vec.push_back("\n");
    OpenServerCommand openServerCommand = OpenServerCommand(symbolTable, varBindMap);
    openServerCommand.doCommand(vec, 0);
    //cout << i << endl;
    sleep(60);
    return 0;
}*/