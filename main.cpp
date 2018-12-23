/*
#include <iostream>
#include <string>
#include "Expression.h"
#include "Lexer.h"
#include "Plus.h"
#include "Num.cpp"
using namespace std;
int main() {

    Lexer* l = new Lexer("lol");
    string s1 = "Var x =\n 2 + 3 127.0.0.1 5402";
    string s2 = "Var x=2+3\n bind \"hello world\"";
    vector<string> v1 = l->splitScript(s1);
    vector<string> v2 = l->splitScript(s2);
    int count = 0;
    for(auto const& string1 : v1) {
        count++;
        if (string1 == "\n") {
            cout<<"\\n"<<endl;
        } else {
            cout<<string1<<endl;
        }
    }
    cout<<count;
    cout<<endl;
    cout<<endl;
    count = 0;
    for(auto const& string1 : v2) {
        count++;
        if (string1 == "\n") {
            cout<<"\\n"<<endl;
        } else {
            cout<<string1<<endl;
        }
    }
    cout<<count;

    */
/*Expression* e = new Plus(*(new Num(5)), *(new Plus(*(new Num(7)), *(new Num(10)))));
    e->evaluate();
    cout << e->toString();*//*

*/
/*
    double d = stod("1.2");
    cout <<d<<endl;
    return 0;*//*

}*/

#include <iostream>
#include "OpenServerCommand.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

#include "PrintCommand.h"

using namespace std;

int main() {
   /* int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;
    portno = 5400;

    *//* First call to socket() function *//*
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    *//* Initialize socket structure *//*
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    cout <<"bind" << endl;
    *//* Now bind the host address using bind() call.*//*
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    cout <<"finish bind" << endl;

    *//* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    *//*

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    cout <<"accept" << endl;
    *//* Accept actual connection from the client *//*
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);

    cout <<"finish accept" << endl;
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    for (int i = 0; i < 6; i++) {
        // If connection is established then start communicating //
        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1023);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);
    }*/
    SymbolTable varsMap = SymbolTable();
    PrintCommand p = PrintCommand(varsMap);
    vector<string> s1;
    vector<string> exp1;
    s1 = {"1","2","-","(","(","3",")",")","5","*","32","\n"};
    exp1 = p.getExpressions(s1, 0);
    cout<<exp1[0]<<"  "<<exp1[1]<<"  "<<exp1[2]<<endl;
    return 0;
}