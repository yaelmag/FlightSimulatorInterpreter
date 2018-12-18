//
// Created by adi on 17/12/18.
//

#ifndef PROJECT1_LEXER_H
#define PROJECT1_LEXER_H
#include <string>
#include <vector>
using namespace std;

class Lexer {
string file;

public:
    Lexer(const string &file);
    string fileToString();
    vector<string> splitScript(string script);
};


#endif //PROJECT1_LEXER_H
