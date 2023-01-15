//
// Created by vesko on 06.01.23.
//

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
        throw std::runtime_error("Wrong type for column: \"" + column_name + "\"");

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

    writer.write_number(out, pos);
    writer.write_number(out, size);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        writer.write_number(out, hash.getHash()[i]);
    }
}

TextCreator::TextCreator() : TypeCreator("string")
{
}

Type *TextCreator::createType(std::istream &in) const
{
    return new Text();
}

static TextCreator __;
