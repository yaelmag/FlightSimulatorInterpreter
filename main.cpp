#include <iostream>
#include <string>
#include "Lexer.h"
using namespace std;
int main() {
    Lexer* l = new Lexer();
    string s1 = "Var x = 2 + 3";
    string s2 = "Var x=2+3";
    vector<string> v1 = l->splitScript(s1);
    vector<string> v2 = l->splitScript(s2);
    int count = 0;
    for(auto const& string1 : v1) {
        count++;
        cout<<string1<<"~";
    }
    cout<<endl;
    cout<<count;
    cout<<endl;
    for(auto const& string1 : v2) {
        cout<<string1<<"~";
    }
    return 0;
}