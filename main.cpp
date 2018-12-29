#include <unistd.h>
#include "iostream"
#include "Lexer.h"
#include "Parser.h"
#include "Client.h"

int main(int argc, char*argv[]) {
    vector<string> splitInfo;
    if (argc < 2) {
        __throw_invalid_argument("There is no file (script) to interpret");
    }
    string fileName = argv[1];
    Lexer l = Lexer(fileName);
    splitInfo = l.splitScript();
    /*for (int i = 0; i < vec.size(); i++) {
        cout<< vec[i]<<" ";
    }*/
    Parser::getInstance();
    Parser::getInstance()->runner(splitInfo, 0);
    Client::getInstance()->closeSocket();
    Client::destroyClient();
    Parser::destroyParser();
    SymbolsTable::destroyInstance();
    return 0;
}