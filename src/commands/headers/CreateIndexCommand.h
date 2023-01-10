//
// Created by vesko on 10.01.23.
//

#ifndef DBMS_CREATEINDEXCOMMAND_H
#define DBMS_CREATEINDEXCOMMAND_H


#include "Command.h"

class CreateIndexCommand
{
public:
    explicit CreateIndexCommand(std::istream &in);
};

class CreateIndexCommandCreator : public CommandCreator
{
public:
    CreateIndexCommandCreator();
    void createCommand(std::istream &in) const override;
};


#endif //DBMS_CREATEINDEXCOMMAND_H
