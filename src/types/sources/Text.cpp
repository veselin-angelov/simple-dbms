//
// Created by vesko on 06.01.23.
//

#include "../headers/Text.h"

Text::Text() : Type("string")
{}

Type *Text::clone() const
{
    return new Text(*this);
}

TextCreator::TextCreator() : TypeCreator("string")
{}

Type *TextCreator::createType(std::istream &in) const
{
    return new Text();
}

static TextCreator __;
