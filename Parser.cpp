//
// Created by adi on 17/12/18.
//

#include "Parser.h"

Parser::Parser() {
    OpenServerCommand openDataServer = OpenServerCommand();
    commands["openDataServer"] = openDataServer;
}