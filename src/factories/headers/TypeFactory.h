//
// Created by vesko on 07.01.23.
//

#ifndef DBMS_TYPEFACTORY_H
#define DBMS_TYPEFACTORY_H


#include <vector>
#include <fstream>
#include "../../types/headers/Type.h"

class TypeFactory
{
private:
    std::vector<const TypeCreator*> creators;

private:
    const TypeCreator* getCreator(const std::string& key) const;

private:
    TypeFactory() = default;
    ~TypeFactory() = default;

public:
    TypeFactory(const TypeFactory&) = delete;
    TypeFactory& operator=(const TypeFactory&) = delete;

public:
    static TypeFactory& getFactory();
    void registerType(const TypeCreator* creator);
    Type* createType(std::istream &in);
};


#endif //DBMS_TYPEFACTORY_H
