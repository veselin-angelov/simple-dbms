//
// Created by vesko on 06.01.23.
//

#include "../headers/Double.h"

Double::Double() : Type("double")
{}

Type *Double::clone() const
{
    return new Double(*this);
}

DoubleCreator::DoubleCreator() : TypeCreator("double")
{}

Type *DoubleCreator::createType(std::istream &in) const
{
    return new Double();
}

static DoubleCreator __;
