//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_ORDER_H
#define SIMPLE_DBMS_ORDER_H


#include <string>

enum class Ordering
{
    ASC,
    DESC
};

class Order
{
private:
    std::string column_name;
    Ordering ordering;

public:
    friend class SelectCommand;
    friend class Select;
};


#endif //SIMPLE_DBMS_ORDER_H
