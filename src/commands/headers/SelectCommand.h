//
// Created by vesko on 10.01.23.
//

#ifndef DBMS_SELECTCOMMAND_H
#define DBMS_SELECTCOMMAND_H


#include "Command.h"

class SelectCommand
{
public:
    explicit SelectCommand(std::istream &in);
};

class SelectCommandCreator : public CommandCreator
{
public:
    SelectCommandCreator();
    void createCommand(std::istream &in) const override;
};


#endif //DBMS_SELECTCOMMAND_H
