//
// Created by adi on 18/12/18.
//

#include "EqualOperatorCommand.h"
#include "Client.h"

EqualOperatorCommand::EqualOperatorCommand() = default;

int EqualOperatorCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    cout<<"in ="<<endl;
    SymbolsTable *symbolsMap = SymbolsTable::getInstance();
    // if the var doesn't exist
    if (!symbolsMap->isSymbolExist(info[index - 2])) {
        __throw_invalid_argument("The var doesn't exist in the map");
    }
    cout<<info[index]<<endl;
    cout<<info[index + 1]<<endl;
    // if the var has bind, connect him to the simulator
    if (info[index] == "bind" && info[index + 2] == "\n") {
        if (info[index + 1][0] == '"') {
            cout<<"in2"<<endl;
            // update the bind of the var in the SymbolsTable
            symbolsMap->setSymbol(info[index - 2], info[index + 1]);
            cout<<"good"<<endl;
        } else {
            // update the bind of the var in the SymbolsTable
            symbolsMap->bindNewSymbolToExistSymbol(info[index - 2], info[index + 1]);
        }
        count = 3;
    } else if (info[index] != "bind") {
        double value;
        // if there is one argument after the "="
        if (info[index + 1] == "\n") {
            // if the argument is var, take his value from the SymbolTable map
            if (symbolsMap->isSymbolExist(info[index])) {
                value = symbolsMap->getSymbolValue(info[index]);
            } else {
                value = stod(info[index]);
            }
            // update the other var with this new value (in the SymbolTable map)
            symbolsMap->setSymbol(info[index - 2], value);
            count = 2;
          // if the argument is expression
        } else {
            CheckExpressions c;
            ShuntingYard s;
            vector<string> exp = c.getExpressions(info, index);
            if (exp.size() != 1) {
                __throw_invalid_argument("There is to many arguments");
            } else {
                value = s.evaluate(exp[0]).evaluate();
                // update the other var with this new value (in the SymbolTable map)
                symbolsMap->setSymbol(info[index - 2], value);
                count = exp[0].length() + 1;
            }
        }
        // if the var before the "=" is connected to the simulator,
        // sent to the simulator the new value
        if (!symbolsMap->getSymbolPath(info[index - 2]).empty() &&
            symbolsMap->getSymbolPath(info[index - 2])[0] == '"') {
            Client::getInstance()->writeData(symbolsMap->getSymbolPath(info[index - 2]), value);
        }
    }
    return count;
}