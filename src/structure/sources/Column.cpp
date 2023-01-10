//
// Created by vesko on 10.01.23.
//

#include "../headers/Column.h"

Column::Column(const std::string &name, Type *type) : name(name), type(type)
{}

Column::~Column()
{
    delete type;
}

const std::string &Column::getName() const
{
    return name;
}

Type *Column::getType() const
{
    return type;
}
