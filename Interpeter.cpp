//
// Created by adi on 17/12/18.
//

#include "Interpeter.h"
#include <sstream>

Interpeter:: Interpeter() {
    OpenServerCommand openDataServer = OpenServerCommand();
    commands["openDataServer"] = openDataServer;
}

vector<string> Interpeter:: lexer(string script) {
    vector<string> splitScript;
    string word = "";

    // go over all the script and split him to words
    for (int i = 0; i < script.length(); i++) {
        // add the current 'word' and ',' to the vector
        if (script[i] == ',') {
            if (word != " ") {
                // add the current word
                splitScript.push_back(word);
            }
            word = "";
            word += script[i];
            // add the ','
            splitScript.push_back(word);
            // reset the word
            word = "";
          // jump over space or tab and add the current 'word'
        } else if ((script[i] == ' ') || (script[i] == '\t')) {
            if (word != " ") {
                // add the current word
                splitScript.push_back(word);
            }
            // reset the word
            word = "";
          // if the current char is arithmetic operator
        } else if (((script[i] == '=') || (script[i] == '+') || (script[i] == '-') ||
                    (script[i] == '/') || (script[i] == '*') || (script[i] == '(') ||
                    (script[i] == ')'))) {
            // if this the first char in the script
            if (i == 0) {
                word += script[i];
                // add the arithmetic operator/token
                splitScript.push_back(word);
                // reset the word
                word = "";
            } else {
                // if the tokens separated with spaces
                if ((script[i - 1] == ' ') || (script[i - 1] == '\t')) {
                    word += script[i];
                    // add the arithmetic operator/token
                    splitScript.push_back(word);
                    // reset the word
                    word = "";
                  // if the tokens don't separated with spaces
                } else {
                    if (word != " ") {
                        // add the current word
                        splitScript.push_back(word);
                    }
                    word = "";
                    word += script[i];
                    // add the arithmetic operator/token
                    splitScript.push_back(word);
                    // reset the word
                    word = "";
                }
            }
        } else {
            word += script[i];
        }
    }
    return splitScript;
}