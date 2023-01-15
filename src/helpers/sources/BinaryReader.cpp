//
// Created by vesko on 11.01.23.
//

#include "../headers/BinaryReader.h"
#include <fstream>

std::string BinaryReader::read_string(std::ifstream &file) const
{
    size_t size = read_size_t(file);

    char* input = new char[size + 1];

    file.read(input, size);
    if (!file.good()) throw std::runtime_error("Something went wrong while reading a string!");

    input[size] = '\0';

    std::string s = input;
    delete[] input;

    return s;
}

unsigned char BinaryReader::read_uchar(std::ifstream &file) const
{
    unsigned char c;
    file.read(reinterpret_cast<char*>(&c), sizeof(c));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a uchar!");

    return c;
}

std::size_t BinaryReader::read_size_t(std::ifstream &file) const
{
    std::size_t num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a size_t!");

    return num;
}

int BinaryReader::read_int(std::ifstream &file) const
{
    int num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a int!");

    return num;
}

double BinaryReader::read_double(std::ifstream &file) const
{
    double num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a double!");

    return num;
}

bool BinaryReader::read_bool(std::ifstream &file) const
{
    bool b;
    file.read(reinterpret_cast<char*>(&b), sizeof(b));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a bool!");

    return b;
}
