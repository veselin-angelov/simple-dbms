//
// Created by vesko on 06.01.23.
//

#include "../headers/Type.h"
#include "../../factories/headers/TypeFactory.h"

Type::Type(const std::string &name) : _name(name)
{}

const std::string &Type::name() const
{
    return _name;
}

TypeCreator::TypeCreator(const std::string &key) : key(key)
{
    TypeFactory::getFactory().registerType(this);
}

const std::string& TypeCreator::getKey() const
{
    return key;
}
