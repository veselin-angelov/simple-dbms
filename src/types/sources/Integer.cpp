//
// Created by vesko on 06.01.23.
//

#include "../headers/Integer.h"

Integer::Integer() : Type("int")
{}

Type *Integer::clone() const
{
    return new Integer(*this);
}

IntegerCreator::IntegerCreator() : TypeCreator("int")
{}

Type *IntegerCreator::createType(std::istream &in) const
{
    return new Integer();
}

static IntegerCreator __;
