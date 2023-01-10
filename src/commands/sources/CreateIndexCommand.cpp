//
// Created by vesko on 10.01.23.
//

#include "../headers/CreateIndexCommand.h"

CreateIndexCommand::CreateIndexCommand(std::istream &in)
{

}

CreateIndexCommandCreator::CreateIndexCommandCreator() : CommandCreator("CREATE INDEX")
{}

void CreateIndexCommandCreator::createCommand(std::istream &in) const
{
    delete new CreateIndexCommand(in);
}

static CreateIndexCommandCreator __;
