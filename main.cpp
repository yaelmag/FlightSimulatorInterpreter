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
    vector<string> splitInfo;
    string fileName = argv[1];
    Lexer l = Lexer(fileName);
    splitInfo = l.splitScript();
    /*string s = "\"/lol/mta/yay\"";
    string t = "yesss";
    cout<<s<<endl;
    string newS = s.substr(2, s.length() - 2);
    cout<<newS<<endl;
    cout<<t<<endl;
    string newT = t.substr(2, t.length() - 3);
    cout<<newT<<endl;*/

    /*for (int i = 0; i < vec.size(); i++) {
        cout<< vec[i]<<" ";
    }*/
    Parser::getInstance();
    Parser::getInstance()->runner(splitInfo, 0);
    /*CheckExpressions c;
    vector<string> v;
    v.push_back("5");
    v.push_back("+");
    v.push_back("4");
    v.push_back(",");
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