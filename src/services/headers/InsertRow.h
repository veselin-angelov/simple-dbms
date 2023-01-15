//
// Created by vesko on 15.01.23.
//

#ifndef DBMS_INSERTROW_H
#define DBMS_INSERTROW_H


#include "../../structure/headers/Table.h"
#include "../../helpers/headers/BinaryWriter.h"

class InsertRow
{
private:
    static BinaryWriter writer;

private:
    void insert(std::map<std::string, std::string> &values, Table &table) const;

public:
    friend class InsertIntoCommand;
};


#endif // DBMS_INSERTROW_H