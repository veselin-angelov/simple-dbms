//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_CREATETABLECOMMAND_H
#define DBMS_CREATETABLECOMMAND_H


#include "../../services/headers/CreateTable.h"
#include "Command.h"

class CreateTableCommand
{
private:
    static CreateTable createTable;

public:
    explicit CreateTableCommand(std::istream &in);

};

class CreateTableCommandCreator : public CommandCreator
{
public:
    CreateTableCommandCreator();
    void createCommand(std::istream &in) const override;
};

#endif //DBMS_CREATETABLECOMMAND_H
