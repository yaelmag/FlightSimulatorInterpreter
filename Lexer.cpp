//
// Created by adi on 17/12/18.
//
#include <iostream>
#include <fstream>
#include "Lexer.h"


Lexer::Lexer(const string &file) {
    this->file = file;
}

/**
 * take the file script and put all his info (all the lines) in one string
 * @return all the script info in one string
 */
string Lexer:: fileToString() {
    ifstream readFile;
    readFile.open(file);
    string line, allScript;
    allScript = "";
    if(!readFile.is_open()) {
        __throw_invalid_argument("can't create the file");
    }
    // push all the script's line in one string
    while (getline(readFile, line)) {
        allScript += line;
        allScript += " ";
        // push also '\n' so we knew when every line end
        allScript += '\n';
        allScript += " ";
    }
    readFile.close();
    return allScript;
}

vector<string> Lexer:: splitScript(string script) {
    // get all the script info in one string
    //string script = fileToString();
    vector<string> splitScript;
    int check = 0;
    string word;

    // go over all the script and split him to words
    for (int i = 0; i < script.length(); i++) {
        if (check == 0) {
            // add the current 'word' and ',' || '\n' to the vector
            if ((script[i] == ',') || (script[i] == '\n')) {
                if ((word != " ") && (!word.empty())) {
                    // add the current word
                    splitScript.push_back(word);
                }
                word = "";
                word += script[i];
                // add the ',' or the '\n'
                splitScript.push_back(word);
                // reset the word
                word = "";
              // if we saw '"' for the first time
            } else if (script[i] == '"') {
                // add the '"'
                word += script[i];
                check = 1;

                // jump over space or tab and add the current 'word'
            } else if ((script[i] == ' ') || (script[i] == '\t')) {
                if ((word != " ") && (!word.empty())) {
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
                        if ((word != " ") && (!word.empty())) {
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
            } else if (script[i] == '}') {
                if ((word != " ") && (!word.empty())) {
                    // add the current word
                    splitScript.push_back(word);
                }
                if (script[i - 1] != '\n') {
                    splitScript.push_back("\n");
                }
                splitScript.push_back("}");
                // reset the word
                word = "";
            } else {
                word += script[i];
            }
          // if we in the '"' keep copy the chars until we saw '"' again
        } else if (check == 1) {
            if (script[i] == '"') {
                check = 0;
                // add the '"'
                word += script[i];
                // add the current word (a bind)
                splitScript.push_back(word);
                // reset the word
                word = "";
            }
            word += script[i];
        }

    }
    if ((word != " ") && (!word.empty()) && (word != "\"")) {
        // add the current word
        splitScript.push_back(word);
    }
    return splitScript;
}