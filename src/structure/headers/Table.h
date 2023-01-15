//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_TABLE_H
#define DBMS_TABLE_H


#include <string>
#include <map>
#include <vector>
#include "../../types/headers/Type.h"
//#include "PrimaryKey.h"
#include "../../constants.h"
#include "Column.h"
#include "../../helpers/headers/BinaryReader.h"

class Table
{
private:
    static BinaryReader reader;

private:
    std::string name;
    std::string path; // std::string(DB_PATH) + name;
    std::vector<Column*> columns;
    Column* primary_key = nullptr;
    std::size_t valid_position = 0;
    std::size_t row_size;

private:
    Table() = default;
    explicit Table(const std::string &name);
    ~Table();

private:
    Column* getColumnByName(std::string& name) const;
    size_t calculateRowSize() const;

    void print() const; // remove

public:
    friend class CreateTableCommand;
    friend class CreateTable;
    friend class InsertIntoCommand;
    friend class InsertRow;
};


#endif //DBMS_TABLE_H
