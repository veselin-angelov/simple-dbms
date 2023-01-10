//
// Created by vesko on 09.01.23.
//

#include "../headers/InsertIntoCommand.h"

InsertIntoCommand::InsertIntoCommand(std::istream &in)
{
// TODO load Table structure, then insert row
}

InsertIntoCommandCreator::InsertIntoCommandCreator() : CommandCreator("INSERT INTO")
{}

void InsertIntoCommandCreator::createCommand(std::istream &in) const
{
    delete new InsertIntoCommand(in);
}

static InsertIntoCommandCreator __;
