//
// Created by vesko on 10.01.23.
//

#ifndef DBMS_COLUMN_H
#define DBMS_COLUMN_H


#include <string>
#include "../../types/headers/Type.h"

class Column
{
private:
    std::string name;
    Type* type;

public:
    Column(const std::string &name, Type *type);
    ~Column();

public:
    const std::string &getName() const;
    Type *getType() const;

public:
    friend class Table;
};


#endif //DBMS_COLUMN_H
