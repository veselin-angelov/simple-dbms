//
// Created by vesko on 07.01.23.
//

#ifndef DBMS_CONSTANTS_H
#define DBMS_CONSTANTS_H

#include <string>
#include <map>

static std::string DB_PATH = "/home/veselin/Documents/DS/simple-dbms/databases/";

enum TypeEnum
{
    INTEGER,
    DOUBLE,
    STRING,
    BOOLEAN,
};

static const std::map<std::string, std::string> types_map = {
        {"int", "int"},
        {"double", "double"},
        {"string", "string"},
        {"bool", "bool"},
};


#endif //DBMS_CONSTANTS_H
