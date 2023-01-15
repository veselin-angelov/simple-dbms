//
// Created by vesko on 15.01.23.
//

#include "../headers/Filter.h"

Filter::Filter(const std::string &key, const Operator &op, const std::string &value) :
        column(key), op(op), value(value)
{}
