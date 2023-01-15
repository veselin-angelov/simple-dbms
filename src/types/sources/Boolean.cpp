//
// Created by vesko on 06.01.23.
//

#include "../headers/Boolean.h"
#include <istream>
#include <iostream>
#include <sstream>

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

    if (!in.good() || (in.peek() != ',' && in.peek() != ')'))
        throw std::runtime_error("Wrong input for boolean column: \"" + column_name + "\"");

    return std::to_string(input);
}

std::size_t Boolean::getSize() const
{
    return sizeof(bool);
}

void Boolean::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    bool b;
    std::stringstream(value.second) >> b;
    writer.write_bool(out, b);
}

std::string Boolean::readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const
{
    std::stringstream value;
    value << std::boolalpha << reader.read_bool(in);
    return value.str();
}

bool Boolean::compare(std::string &val1, std::string &val2, std::string &op) const
{
    bool a;
    bool b;
    std::stringstream(val1) >> std::boolalpha >> a;
    std::stringstream(val2) >> std::boolalpha >> b;

    if (op == "=") return a == b;
    if (op == "!=") return a != b;

    throw std::runtime_error("Invalid operator");
}

BooleanCreator::BooleanCreator() : TypeCreator("bool")
{
}

Type *BooleanCreator::createType(std::istream &in) const
{
    return new Boolean();
}

static BooleanCreator __;
