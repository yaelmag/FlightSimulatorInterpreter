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
#include "CheckExpressions.h"

int main(int argc, char*argv[]) {
    vector<string> vec;
    string fileName = argv[1];
    Lexer l = Lexer(fileName);
    vec = l.splitScript();
    /*for (int i = 0; i < vec.size(); i++) {
        cout<< vec[i]<<" ";
    }*/
    Parser::getInstance();
    Parser::getInstance()->runner(vec, 0);
    /*CheckExpressions c;
    vector<string> v;
    v.push_back("5");
    v.push_back("+");
    v.push_back("4");
    v.push_back(",");
    v.push_back("-");
    v.push_back("3");
    v.push_back("\n");
    cout<<"ok"<<endl;
    vector<string> exp = c.getExpressions(v, 0);
    cout<<"ok2"<<endl;
    for (int i = 0; i < exp.size(); i++) {
        cout<< exp[i]<<endl;
    }*/
    return 0;
}