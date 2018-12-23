
#include <unistd.h>
#include "SymbolTable.h"
#include "VarBindMap.h"
#include "OpenServerCommand.h"
#include "iostream"
#include "Lexer.h"

int main() {
        Lexer l = Lexer("lol.txt");
        vector<string> v = l.splitScript("open heading-2 3 \n");
        for (int i = 0; i < v.size(); i++) {
                cout<<v[i]<<endl;
        }
        return 0;
    }