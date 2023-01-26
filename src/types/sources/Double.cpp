//
// Created by vesko on 06.01.23.
//

#include "../headers/Double.h"
#include <istream>
#include <iostream>

Double::Double() : Type("double")
{
}

Type *Double::clone() const
{
    return new Double(*this);
}

std::string Double::readValue(const std::string &column_name, std::istream &in) const
{
    double input;

    in >> input;

    if (!in.good() || (in.peek() != ',' && in.peek() != ')'))
        throw std::runtime_error("Wrong input for double column_name: \"" + column_name + "\"");

    return std::to_string(input);
}

std::size_t Double::getSize() const
{
    return sizeof(double);
}

void Double::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    writer.write_double(out, std::stod(value.second));
}

std::string Double::readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const
{
    std::string value = std::to_string(reader.read_double(in));
    return value;
}

bool Double::compare(const std::string &val1, const std::string &val2, const std::string &op) const
{
    double a = std::stod(val1);
    double b = std::stod(val2);

    if (op == ">") return a > b;
    if (op == "<") return a < b;
    if (op == ">=") return a >= b;
    if (op == "<=") return a <= b;
    if (op == "=") return a == b;
    if (op == "!=") return a != b;

    throw std::runtime_error("Invalid operator");
}

DoubleCreator::DoubleCreator() : TypeCreator("double")
{
}

Type *DoubleCreator::createType(std::istream &in) const
{
    return new Double();
}

static DoubleCreator __;
