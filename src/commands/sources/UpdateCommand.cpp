//
// Created by vesko on 10.01.23.
//
#include "../headers/UpdateCommand.h"

UpdateCommand::UpdateCommand(std::istream &in)
{

}

UpdateCommandCreator::UpdateCommandCreator() : CommandCreator("UPDATE")
{}

void UpdateCommandCreator::createCommand(std::istream &in) const
{
    delete new UpdateCommand(in);
}

static UpdateCommandCreator __;
