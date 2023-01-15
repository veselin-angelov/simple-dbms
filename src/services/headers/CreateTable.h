//
// Created by vesko on 15.01.23.
//

#ifndef DBMS_CREATETABLE_H
#define DBMS_CREATETABLE_H


#include "../../structure/headers/Table.h"
#include "../../helpers/headers/BinaryWriter.h"

class CreateTable
{
private:
    static BinaryWriter writer;

private:
    void create(const Table &table) const;
    void create_data_files(const Table &table) const;

public:
    friend class CreateTableCommand;
};


#endif // DBMS_CREATETABLE_H