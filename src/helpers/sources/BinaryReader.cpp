//
// Created by vesko on 11.01.23.
//

#include "../headers/BinaryReader.h"
#include <fstream>

std::string BinaryReader::read_string(std::ifstream &file) const
{
    size_t size = read_number(file);

    char* input = new char[size + 1];

    file.read(input, size);
    if (!file.good()) throw std::runtime_error("Something went wrong while reading a string!");

    input[size] = '\0';

    std::string s = input;
    delete[] input;

    return s;
}

size_t BinaryReader::read_number(std::ifstream &file) const
{
    size_t size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    if (!file.good()) throw std::runtime_error("Something went wrong while reading a number!");

    return size;
}
