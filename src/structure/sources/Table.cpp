//
// Created by vesko on 06.01.23.
//

#include <iostream> // TODO remove
#include "../headers/Table.h"

//Table::Table(const std::string &name) : name(name)
//{
//
//}
void Table::print() const
{
    std::cout <<
        name << " " <<
        path << " " <<
        (primary_key ? primary_key->getName() : "") <<
        valid_position << std::endl;

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

Table::~Table()
{
    for (auto &column: columns)
    {
        delete column;
    }
}
