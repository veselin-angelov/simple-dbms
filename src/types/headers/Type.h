//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_TYPE_H
#define DBMS_TYPE_H

#include <string>
#include "../../helpers/headers/BinaryWriter.h"
#include "../../helpers/headers/BinaryReader.h"

class Type
{
private:
    const std::string _name;

public:
    explicit Type(const std::string &name);
    virtual ~Type() = default;
    virtual Type *clone() const = 0;

public:
    const std::string &name() const;
    virtual std::string readValue(const std::string &column_name, std::istream &in) const = 0;
    virtual std::size_t getSize() const = 0;
    virtual void writeToFile(BinaryWriter &writer, std::ofstream &out, const std::pair<const std::string, const std::string> &value, const std::string &table_path) const = 0;
    virtual std::string readFromFile(BinaryReader &reader, std::ifstream &in, const std::string &table_path) const = 0;
    virtual bool compare(std::string &val1, std::string &val2, std::string &op) const = 0;
};

class TypeCreator
{
private:
    const std::string key;

public:
    explicit TypeCreator(const std::string &key);
    virtual ~TypeCreator() = default;
    TypeCreator(const TypeCreator &) = delete;
    TypeCreator &operator=(const TypeCreator &) = delete;

public:
    const std::string &getKey() const;
    virtual Type *createType(std::istream &in) const = 0;
};

#endif // DBMS_TYPE_H
