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

    return std::to_string(input);
}

std::size_t Double::getSize() const
{
    return sizeof(double);
}

void Double::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    writer.write_number(out, std::stod(value.second));
}

DoubleCreator::DoubleCreator() : TypeCreator("double")
{
}

Type *DoubleCreator::createType(std::istream &in) const
{
    return new Double();
}

static DoubleCreator __;
