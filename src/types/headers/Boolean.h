//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_BOOLEAN_H
#define DBMS_BOOLEAN_H


#include "Type.h"

class Boolean : public Type
{
public:
    Boolean();
    Type *clone() const override;
};

class BooleanCreator : public TypeCreator
{
public:
    BooleanCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_BOOLEAN_H
