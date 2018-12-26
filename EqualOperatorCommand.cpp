//
// Created by adi on 18/12/18.
//

#include "EqualOperatorCommand.h"

EqualOperatorCommand::EqualOperatorCommand() = default;

int EqualOperatorCommand:: doCommand(vector<string> info, int index) {
    int count = 0;
    SymbolsTable *symbolsMap = SymbolsTable::getInstance();
    // if the var doesn't exist
    if (!symbolsMap->isSymbolExist(info[index])) {
        __throw_invalid_argument("The var doesn't exist in the map");
    }

    // if the var has bind, connect him to the simulator
    if (info[index + 2] == "bind" && info[index + 4] == "\n") {
        if (info[index + 3][0] == '"') {
            // update the bind of the var in the SymbolsTable
            symbolsMap->setSymbol(info[index], info[index + 3]);
        } else {
            // update the bind of the var in the SymbolsTable
            symbolsMap->bindNewSymbolToExistSymbol(info[index], info[index + 3]);
        }

        //todo
        //להכניס ממש את הערך שיש בסימולטור לתוך הסימבול טייבל
        count = 5;
    } else if (info[index + 2] != "bind") {
        double value;
        // if there is one argument after the "="
        if (info[index + 3] == "\n") {
            // if the argument is var, take his value from the SymbolTable map
            if (symbolsMap->isSymbolExist(info[index + 2])) {
                value = symbolsMap->getSymbolValue(info[index + 2]);
            } else {
                value = stod(info[index + 2]);
            }
            // update the other var with this new value (in the SymbolTable map)
            symbolsMap->setSymbol(info[index], value);
            count = 4;
          // if the argument is expression
        } else {
            CheckExpressions c;
            ShuntingYard s;
            vector<string> exp = c.getExpressions(info, index + 2);
            if (exp.size() != 1) {
                __throw_invalid_argument("There is to many arguments");
            } else {
                value = s.evaluate(exp[0]).evaluate();
                // update the other var with this new value (in the SymbolTable map)
                symbolsMap->setSymbol(info[index], value);
                count = exp[0].length() + 3;
            }
        }
        // if the var before the "=" is connected to the simulator,
        // sent to the simulator the new value
        if (!symbolsMap->getSymbolPath(info[index]).empty() &&
            symbolsMap->getSymbolPath(info[index])[0] == '"') {
            //todo
            //לעדכן את הסימולטור עם הערך החדש
        }
    }
    return count;
}