//
// Created by vesko on 15.01.23.
//

#include <iostream>
#include <algorithm>
#include "../headers/Select.h"

void Select::select(Table &table, std::vector<std::string> &column_names, Filter &filter, Order &order) const
{
    std::ifstream table_file_data(table.path + ".data", std::ios::binary);

    if (!table_file_data.is_open()) throw std::runtime_error("Could not open file!");

    std::vector<std::map<std::string, std::string>> rows;

    if (column_names.empty())
    {
        rows = get_rows(table, table.columns, table_file_data, filter);
    }
    else
    {
        std::vector<Column *> selected_columns = getSelectedColumns(table, column_names);
        rows = get_rows(table, selected_columns, table_file_data, filter);
    }

    for (auto &row: rows)
    {
        for (auto &col: row)
        {
            std::cout << col.first << ": " << col.second << ", ";
        }
        std::cout << std::endl;
    }
}

bool Select::where(Table &table,
                   std::ifstream &table_file_data,
                   Filter &filter) const
{
    std::string value;

    Column *col = table.getColumnByName(filter.column);

    value = col->getType()->readFromFile(
            reader,
            table_file_data,
            table.path + ".data." + filter.column);

    return !col->getType()->compare(value, filter.value, filter.op.value);
}

std::vector<std::map<std::string, std::string>> Select::get_rows(
        Table &table,
        std::vector<Column*> &selected_columns,
        std::ifstream &table_file_data,
        Filter &filter
    ) const
{
    std::string value;
    std::size_t index = 0;

    std::vector<std::map<std::string, std::string>> rows;
    std::map<std::string, std::string> row;

    while (table_file_data.tellg() < table.valid_position)
    {
        if (!filter.column.empty())
        {
            table_file_data.seekg(
                    (index * table.row_size) + table.getOffset(filter.column), std::ios::beg);

            if (where(table, table_file_data, filter))
            {
                index++;
                table_file_data.seekg(index * table.row_size, std::ios::beg);
                continue;
            }
        }

        for (auto &column: selected_columns)
        {
            table_file_data.seekg(
                    (index * table.row_size) + table.getOffset(column->getName()), std::ios::beg);

            value = column->getType()->readFromFile(
                    reader,
                    table_file_data,
                    table.path + ".data." + column->getName());

            row[column->getName()] = value;
        }
        rows.push_back(row);
        row.clear();

        index++;
        table_file_data.seekg(index * table.row_size, std::ios::beg);
    }

    return rows;
}

std::vector<Column *> Select::getSelectedColumns(Table &table, std::vector<std::string> &column_names) const
{
    std::vector<Column*> selected_columns;

    for (auto &column_name: column_names)
    {
        auto it = std::find_if(
                table.columns.begin(),
                table.columns.end(),
                [&column_name](Column *&col)
                { return col->getName() == column_name; }
        );

        if (it != table.columns.end())
        {
            selected_columns.push_back(*it);
        }
    }

    return selected_columns;
}

BinaryReader Select::reader = BinaryReader();
