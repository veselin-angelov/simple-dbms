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

void BinaryWriter::write_uchar(std::ofstream &file, const unsigned char data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a uchar!");
}

void BinaryWriter::write_size_t(std::ofstream &file, const size_t data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a size_t!");
}

void BinaryWriter::write_int(std::ofstream &file, const int data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a int!");
}

void BinaryWriter::write_double(std::ofstream &file, const double data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a double!");
}

void BinaryWriter::write_bool(std::ofstream &file, const bool data) const
{
    file.write(reinterpret_cast<const char*>(&data), sizeof(data));
    if (!file.good()) throw std::runtime_error("Something went wrong while writing a bool!");
}
