//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_DOUBLE_H
#define DBMS_DOUBLE_H


#include "Type.h"

class Double : public Type
{
public:
    Double();
    Type *clone() const override;
};

class DoubleCreator : public TypeCreator
{
public:
    DoubleCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_DOUBLE_H
