//
// Created by vesko on 09.01.23.
//

#ifndef DBMS_UPDATECOMMAND_H
#define DBMS_UPDATECOMMAND_H


#include "Command.h"

class UpdateCommand
{
public:
    explicit UpdateCommand(std::istream &in);
};

class UpdateCommandCreator : public CommandCreator
{
public:
    UpdateCommandCreator();
    void createCommand(std::istream &in) const override;
};


#endif //DBMS_UPDATECOMMAND_H
