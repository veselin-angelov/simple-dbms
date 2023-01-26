//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_TEXT_H
#define DBMS_TEXT_H


#include "Type.h"

class Text : public Type
{
public:
    Text();
    Type *clone() const override;

public:
    std::string readValue(const std::string &column_name, std::istream &in) const override;
    std::size_t getSize() const override;
    void writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const override;
    std::string readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const override;
    bool compare(const std::string &val1, const std::string &val2, const std::string &op) const override;
};

class TextCreator : public TypeCreator
{
public:
    TextCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_TEXT_H
