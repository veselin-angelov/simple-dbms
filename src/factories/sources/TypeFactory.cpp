//
// Created by vesko on 07.01.23.
//

#include <stdexcept>
#include "../headers/TypeFactory.h"

const TypeCreator* TypeFactory::getCreator(const std::string &key) const
{
    for (auto &creator: creators)
    {
        if (creator->getKey() == key)
        {
            return creator;
        }
    }
    return nullptr;
}

TypeFactory &TypeFactory::getFactory()
{
    static TypeFactory theFactory;
    return theFactory;
}

void TypeFactory::registerType(const TypeCreator *creator)
{
    creators.push_back(creator);
}

Type* TypeFactory::createType(std::istream &in)
{
    std::string type;

    in >> type;

    while (type.back() == ';' || type.back() == ')')
    {
        in.unget();
        type.pop_back();
    }

    if (type.back() == ',') type.pop_back();

    const TypeCreator* creator = getCreator(type);

    if (creator)
    {
        return creator->createType(in);
    }

    throw std::invalid_argument("Type '" + type + " 'doesn't exist or format of the command is wrong!");
}
