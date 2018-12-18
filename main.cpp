#include <iostream>
#include <string>
#include "Expression.h"
#include "Plus.h"
#include "Num.cpp"
using namespace std;
int main() {
    /*
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
    Expression* e = new Plus(*(new Num(5)), *(new Plus(*(new Num(7)), *(new Num(10)))));
    e->evaluate();
    cout << e->toString();
    return 0;
}