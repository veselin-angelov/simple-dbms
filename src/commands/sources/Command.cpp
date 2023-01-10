//this
// Created by vesko on 09.01.23.
//

#include "../headers/Command.h"
#include "../../factories/headers/CommandFactory.h"

CommandCreator::CommandCreator(const std::string &key) : key(key)
{
    CommandFactory::getFactory().registerCommand(this);
}

const std::string& CommandCreator::getKey() const
{
    return key;
}
