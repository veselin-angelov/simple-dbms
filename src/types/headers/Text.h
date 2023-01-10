//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_TEXT_H
#define DBMS_TEXT_H


#include "Type.h"

class Text : public Type
{
public:
    Text();
    Type *clone() const override;
};

class TextCreator : public TypeCreator
{
public:
    TextCreator();
    Type* createType(std::istream &in) const override;
};


#endif //DBMS_TEXT_H
