//
// Created by vesko on 06.01.23.
//

#include "../headers/Boolean.h"
#include <istream>
#include <iostream>

Boolean::Boolean() : Type("bool")
{
}

Type *Boolean::clone() const
{
    return new Boolean(*this);
}

std::string Boolean::readValue(const std::string &column_name, std::istream &in) const
{
    bool input;

    in >> std::boolalpha >> input;

    if (!in.good()) throw std::runtime_error("Wrong input for boolean column: \"" + column_name + "\"");

    return std::to_string(input);
}

std::size_t Boolean::getSize() const
{
    return sizeof(bool);
}

void Boolean::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    writer.write_number(out, std::stoi(value.second));
}

BooleanCreator::BooleanCreator() : TypeCreator("bool")
{
}

Type *BooleanCreator::createType(std::istream &in) const
{
    return new Boolean();
}

static BooleanCreator __;
