//
// Created by vesko on 11.01.23.
//

#include <fstream>
#include "../headers/BinaryWriter.h"

void BinaryWriter::write_string(std::ofstream& file, const std::string &data) const
{
    size_t size = data.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing string length!");
    file.write(reinterpret_cast<const char*>(data.c_str()), size);
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a string!");
}

void BinaryWriter::write_number(std::ofstream &file, const long long data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a number!");
}
