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

class Table
{
private:
    std::string name;
    std::string path; // = std::string(DB_PATH) + name;
    std::vector<Column*> columns;
    Column* primary_key = nullptr;
    std::size_t valid_position = 0;

public:
//    explicit Table(const std::string &name);
    ~Table();

//    func loadTable(name)
    void print() const;

    Column* getColumnByName(std::string& name) const;

public:
    friend class CreateTableCommand;
};


#endif //DBMS_TABLE_H
