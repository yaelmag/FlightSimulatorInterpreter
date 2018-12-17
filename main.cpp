#include <iostream>
#include <string>
#include "Interpeter.h"
using namespace std;
int main() {
    Interpeter* p = new Interpeter();
    string s1 = "Var x = 2 + 3";
    string s2 = "Var x=2+3";
    vector<string> v1 = p->lexer(s1);
    vector<string> v2 = p->lexer(s2);
    for(auto const& string1 : v1) {
        cout<<string1<<"~";
    }
    cout<<endl;
    for(auto const& string1 : v2) {
        cout<<string1<<"~";
    }
    return 0;
}