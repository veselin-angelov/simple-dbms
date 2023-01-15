//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_FILTER_H
#define SIMPLE_DBMS_FILTER_H


#include <string>
#include "Operator.h"

class Filter
{
public:
    std::string column;
    Operator op;
    std::string value;

public: // maybe
    Filter() = default;
    Filter(const std::string &key, const Operator &op, const std::string &value);

};


#endif //SIMPLE_DBMS_FILTER_H
