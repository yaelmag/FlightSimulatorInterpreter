//
// Created by adi on 18/12/18.
//

#include "ConnectCommand.h"
#include "Client.h"

ConnectCommand::ConnectCommand() {
}

int ConnectCommand:: doCommand(vector<string> info, int index) {
    string strIp;
    int port, count;
    if (info.at(index + 2) == "\n") {
        count = 3;
        strIp = info.at(index);
        try {
            port = stoi(info.at(index+1));
        } catch (...) {
            throw "invalid type of argument (required int)";
        }
    } else {
        CheckExpressions c;
        ShuntingYard s;
        vector<string> exp = c.getExpressions(info, index + 1);
        if (exp.size() != 1) {
            __throw_invalid_argument("The number of arguments not ok");
        }
        strIp = info.at(index);
        try {
            port = (int)s.evaluate(exp[0]).evaluate();
        } catch (...) {
            throw "invalid type of argument (required int)";
        }
        count = exp[0].length() + 2;
    }

    //char* ipByName = strcpy((char*)malloc(strIp.length() + 1), strIp.c_str());
    cout<<"connect"<<endl;
    Client::getInstance();
    cout << "port = " + port << endl;
    Client::getInstance()->setPort(port);
    cout << "ip = " << strIp << endl;
    Client::getInstance()->setIp(strIp);
    Client::getInstance()->openSocket();
    return count;
}