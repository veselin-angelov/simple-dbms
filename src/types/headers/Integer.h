//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_INTEGER_H
#define DBMS_INTEGER_H


#include "Type.h"

class Integer : public Type
{
public:
    Integer();
    Type *clone() const override;

public:
    std::string readValue(const std::string &column_name, std::istream &in) const override;
    std::size_t getSize() const override;
    void writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const override;

};

class IntegerCreator : public TypeCreator
{
public:
    IntegerCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_INTEGER_H
