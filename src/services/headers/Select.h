//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_SELECT_H
#define SIMPLE_DBMS_SELECT_H


#include "../../helpers/headers/BinaryReader.h"
#include "../../structure/headers/Table.h"
#include "../../structure/headers/Filter.h"
#include "../../structure/headers/Order.h"

class Select
{
private:
    static BinaryReader reader;

private:
    void select(Table &table, std::vector<std::string> &column_names, Filter &filter, Order &order) const;

private:
    bool where(Table &table, std::ifstream &table_file_data, Filter &filter) const;

    std::vector<std::map<std::string, std::string>>
        get_rows(Table &table, std::vector<Column*> &selected_columns, std::ifstream &table_file_data, Filter &filter) const;

    std::vector<Column*> getSelectedColumns(Table &table, std::vector<std::string> &column_names) const;

public:
    friend class SelectCommand;
    friend class InsertIntoCommand;

};


#endif //SIMPLE_DBMS_SELECT_H
