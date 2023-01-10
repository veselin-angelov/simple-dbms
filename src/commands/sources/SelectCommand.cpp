//
// Created by vesko on 10.01.23.
//

#include "../headers/SelectCommand.h"

SelectCommand::SelectCommand(std::istream &in)
{

}

SelectCommandCreator::SelectCommandCreator() : CommandCreator("SELECT")
{}

void SelectCommandCreator::createCommand(std::istream &in) const
{
    delete new SelectCommand(in);
}

static SelectCommandCreator __;
