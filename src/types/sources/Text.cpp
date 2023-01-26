//
// Created by vesko on 06.01.23.
//

#include <iostream>
#include <iomanip>
#include "../headers/Text.h"
#include "../../helpers/headers/Hash.h"

Text::Text() : Type("string")
{
}

Type *Text::clone() const
{
    return new Text(*this);
}

std::string Text::readValue(const std::string &column_name, std::istream &in) const
{
    char c = in.get();

    if (c != '"')
        throw std::runtime_error("Wrong type for column_name: \"" + column_name + "\"");

    std::string input;
    char delim;

    while (c = in.get())
    {
        if (c == '"' && ((delim = in.peek()) == ',' || delim == ')'))
            break;
        input += c;
    }

    return input;
}

std::size_t Text::getSize() const
{
    return sizeof(size_t) + sizeof(size_t) + SHA256_DIGEST_LENGTH;
}

void Text::writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const
{
    std::ofstream string_file(table_path + "." + value.first, std::ios::binary | std::ios::app);

    std::size_t pos = string_file.tellp();
    std::size_t size = value.second.size();
    Hash hash(value.second);

    writer.write_string(string_file, value.second);

    writer.write_size_t(out, pos);
    writer.write_size_t(out, size);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        writer.write_uchar(out, hash.getHash()[i]);
    }
}

std::string Text::readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const
{
    std::size_t pos = reader.read_size_t(in);
    std::size_t size = reader.read_size_t(in);

    in.seekg(SHA256_DIGEST_LENGTH, std::ios::cur);

//    std::cout << std::endl;
//    unsigned char hash[SHA256_DIGEST_LENGTH];
//
//    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//    {
//        hash[i] = reader.read_uchar(in);
//        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
//    }
//    std::cout << std::endl;

    std::ifstream string_file(table_path , std::ios::binary);
    string_file.seekg(pos);
    std::string value = reader.read_string(string_file);

    return value;
}

bool Text::compare(const std::string &val1, const std::string &val2, const std::string &op) const
{
    if (op == ">") return val1 > val2;
    if (op == "<") return val1 < val2;
    if (op == ">=") return val1 >= val2;
    if (op == "<=") return val1 <= val2;
    if (op == "=") return val1 == val2;
    if (op == "!=") return val1 != val2;

    throw std::runtime_error("Invalid operator");
}

TextCreator::TextCreator() : TypeCreator("string")
{
}

Type *TextCreator::createType(std::istream &in) const
{
    return new Text();
}

static TextCreator __;
