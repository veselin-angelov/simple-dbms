//
// Created by vesko on 15.01.23.
//

#include "../headers/CreateTable.h"

void CreateTable::create(const Table &table) const
{
    std::ifstream f(table.path);
    if (f.good()) throw std::invalid_argument("Table " + table.name + " already exists!");

    std::ofstream table_file(table.path, std::ios::binary);

    if (!table_file.is_open()) throw std::runtime_error("Opening table file failed!");

    writer.write_number(table_file, table.valid_position);

    size_t size = table.columns.size();
    writer.write_number(table_file, size);

    for (auto &column: table.columns)
    {
        writer.write_string(table_file, column->getName());
        writer.write_string(table_file, column->getType()->name());
    }

    if (table.primary_key) writer.write_string(table_file, table.primary_key->getName());

    create_data_files(table);

    table.print();
}

void CreateTable::create_data_files(const Table &table) const
{
    std::ofstream table_data_file(table.path + ".data", std::ios::binary);

    std::ofstream table_type_file;
    for (auto &column: table.columns)
    {
        if (column->getType()->name() == "string")
        {
            table_type_file.open(table.path + ".data." + column->getName(), std::ios::binary);
            table_type_file.close();
        }
    }
}

BinaryWriter CreateTable::writer = BinaryWriter();
