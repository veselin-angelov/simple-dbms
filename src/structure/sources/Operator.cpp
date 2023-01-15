//
// Created by vesko on 15.01.23.
//

#include <stdexcept>
#include "../headers/Operator.h"

Operator::Operator(const std::string &value) : value(value)
{}

bool Operator::isOperator(char c)
{
//    todo make it better
    if (c == '=' || c == '<' || c == '>' || c == '!') return true;
    return false;
}

void Operator::validateOperator(Operator &op)
{
    if (!(op.value == "=" || op.value == "<" || op.value == ">" || op.value == "<=" || op.value == ">=" || op.value == "!="))
        throw std::runtime_error("Wrong operator");
}
