//
// Created by vesko on 06.01.23.
//

#include "../headers/Integer.h"
#include <istream>
#include <iostream>

Integer::Integer() : Type("int")
{
}

Type *Integer::clone() const
{
    return new Integer(*this);
}

std::string Integer::readValue(const std::string &column_name, std::istream &in) const
{
    int input;

    in >> input;

    return std::to_string(input);
}

std::size_t Integer::getSize() const
{
    return sizeof(int);
}

void Integer::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    writer.write_number(out, std::stoi(value.second));
}

IntegerCreator::IntegerCreator() : TypeCreator("int")
{
}

Type *IntegerCreator::createType(std::istream &in) const
{
    return new Integer();
}

static IntegerCreator __;
