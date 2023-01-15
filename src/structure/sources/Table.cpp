//
// Created by vesko on 06.01.23.
//

#include <iostream> // TODO remove
#include <fstream>
#include <sstream>
#include "../headers/Table.h"
#include "../../factories/headers/TypeFactory.h"

Table::Table(const std::string &name) : name(name)
{
    path = DB_PATH + name;

    std::ifstream file(path, std::ios::binary);

    if (!file.is_open()) throw std::runtime_error("Opening table file failed!");

    valid_position = reader.read_size_t(file);

    size_t columns_count = reader.read_size_t(file);

    std::string column_name;
    std::string column_type_name;

    for (; columns_count > 0; columns_count--)
    {
        column_name = reader.read_string(file);
        column_type_name = reader.read_string(file);

        std::stringstream ss;
        ss << column_type_name;

        columns.push_back(new Column(column_name, TypeFactory::getFactory().createType(ss)));
    }

    row_size = calculateRowSize();
//    TODO load which table have index also write it in the file, when index is created

    file.peek();
    if (!file.good()) return;

    std::string pk = reader.read_string(file);
    primary_key = getColumnByName(pk);
}

void Table::print() const
{
    std::cout <<
        name << " " <<
        path << " " <<
        (primary_key ? primary_key->getName() : "") << " " <<
        valid_position << " " <<
        row_size << std::endl;

    for (auto &column: columns)
    {
        std::cout << column->getName() << ": " << column->getType()->name() << std::endl;
    }
}

Column *Table::getColumnByName(std::string &name) const
{
    for (auto &column: columns)
    {
        if (column->name == name)
        {
            return column;
        }
    }

    return nullptr;
}

size_t Table::calculateRowSize() const
{
    size_t size = 0;

    for (auto &column: columns)
    {
        size += column->getType()->getSize();
    }

    return size;
}

std::size_t Table::getOffset(const std::string &column_name) const
{
    size_t size = 0;

    for (auto &column: columns)
    {
        if (column->getName() == column_name) break;

        size += column->getType()->getSize();
    }

    return size;
}


Table::~Table()
{
    for (auto &column: columns)
    {
        delete column;
    }
}

BinaryReader Table::reader = BinaryReader();
