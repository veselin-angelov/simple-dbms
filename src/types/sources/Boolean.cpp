//
// Created by vesko on 06.01.23.
//

#include "../headers/Boolean.h"

Boolean::Boolean() : Type("bool")
{}

Type *Boolean::clone() const
{
    return new Boolean(*this);
}

BooleanCreator::BooleanCreator() : TypeCreator("bool")
{}

Type *BooleanCreator::createType(std::istream &in) const
{
    return new Boolean();
}

static BooleanCreator __;
