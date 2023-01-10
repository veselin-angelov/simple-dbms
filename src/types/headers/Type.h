//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_TYPE_H
#define DBMS_TYPE_H


#include <string>

class Type
{
private:
    const std::string _name;

public:
    explicit Type(const std::string &name);
    virtual ~Type() = default;
    virtual Type* clone() const = 0;

public:
    const std::string& name() const;

//    virtual std::string name() const = 0;
};


class TypeCreator
{
private:
    const std::string key;

public:
    explicit TypeCreator(const std::string &key);
    virtual ~TypeCreator() = default;
    TypeCreator(const TypeCreator&) = delete;
    TypeCreator& operator=(const TypeCreator&) = delete;

public:
    const std::string& getKey() const;
    virtual Type* createType(std::istream &in) const = 0;
};


#endif //DBMS_TYPE_H
