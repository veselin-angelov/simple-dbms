//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_INTEGER_H
#define DBMS_INTEGER_H


#include "Type.h"

class Integer : public Type
{
public:
    Integer();
    Type *clone() const override;
};

class IntegerCreator : public TypeCreator
{
public:
    IntegerCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_INTEGER_H
