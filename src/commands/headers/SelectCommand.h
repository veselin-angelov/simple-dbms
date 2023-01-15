//
// Created by vesko on 10.01.23.
//

#ifndef DBMS_SELECTCOMMAND_H
#define DBMS_SELECTCOMMAND_H


#include "Command.h"
#include "../../structure/headers/Table.h"
#include "../../structure/headers/Filter.h"
#include "../../services/headers/Select.h"
#include "../../structure/headers/Order.h"

class SelectCommand
{
private:
    static Select select_;

public:
    explicit SelectCommand(std::istream &in);

private:
    void checkIfColumnsExist(std::vector<std::string> &column_names, Table &table) const;
    Filter handleWhereClause(std::istream &in, Table &table) const;
    Order handleOrderClause(std::istream &in, Table &table) const;

};

class SelectCommandCreator : public CommandCreator
{
public:
    SelectCommandCreator();
    void createCommand(std::istream &in) const override;
};


#endif //DBMS_SELECTCOMMAND_H
