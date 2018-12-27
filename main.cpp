#include <unistd.h>
#include "SymbolTable.h"
#include "VarBindMap.h"
#include "OpenServerCommand.h"
#include "iostream"
#include "BooleanExpression.h"
#include "Greater.h"
#include "Client.h"
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char*argv[]) {
    vector<string> vec;
    string fileName = argv[1];
    Lexer l = Lexer(fileName);
    vec = l.splitScript();
    /*for (int i = 0; i < vec.size(); i++) {
        cout<< vec[i];
    }*/
    Parser::getInstance();
    Parser::getInstance()->runner(vec, 0);
    return 0;
}