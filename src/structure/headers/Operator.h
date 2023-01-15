//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_OPERATOR_H
#define SIMPLE_DBMS_OPERATOR_H


#include <string>

class Operator
{
public:
    std::string value;

public:
    Operator() = default;
    explicit Operator(const std::string &value);

public:
    static bool isOperator(char c);
    static void validateOperator(Operator &op);
};


#endif //SIMPLE_DBMS_OPERATOR_H
