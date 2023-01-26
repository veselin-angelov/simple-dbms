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

    if (!in.good() || (in.peek() != ',' && in.peek() != ')'))
        throw std::runtime_error("Wrong input for int column_name: \"" + column_name + "\"");

    return std::to_string(input);
}

std::size_t Integer::getSize() const
{
    return sizeof(int);
}

void Integer::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    writer.write_int(out, std::stoi(value.second));
}

std::string Integer::readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const
{
    std::string value = std::to_string(reader.read_int(in));
    return value;
}

bool Integer::compare(const std::string &val1, const std::string &val2, const std::string &op) const
{
    int a = std::stoi(val1);
    int b = std::stoi(val2);

    if (op == ">") return a > b;
    if (op == "<") return a < b;
    if (op == ">=") return a >= b;
    if (op == "<=") return a <= b;
    if (op == "=") return a == b;
    if (op == "!=") return a != b;

    throw std::runtime_error("Invalid operator");
}

IntegerCreator::IntegerCreator() : TypeCreator("int")
{
}

Type *IntegerCreator::createType(std::istream &in) const
{
    return new Integer();
}

static IntegerCreator __;
