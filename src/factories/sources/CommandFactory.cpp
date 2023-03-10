//
// Created by vesko on 09.01.23.
//

#include <iostream> // TODO remove
#include "../headers/CommandFactory.h"

const CommandCreator* CommandFactory::getCreator(const std::string &key) const
{
//    std::cout << key << std::endl;

    for (auto &creator: creators)
    {
        if (creator->getKey() == key)
        {
            return creator;
        }
    }
    return nullptr;
}

CommandFactory &CommandFactory::getFactory()
{
    static CommandFactory theFactory;
    return theFactory;
}

void CommandFactory::registerCommand(const CommandCreator *creator)
{
    creators.push_back(creator);
}

bool CommandFactory::createCommand(std::istream &in)
{
    std::string command;
    char c;

    while ((c = in.get()) >= 'A' && c <= 'Z' || c == ' ')
    {
        command += c;
    }

    if (command.back() == ' ') command.pop_back();

    if (command == "QUIT") return false;

    const CommandCreator* creator = getCreator(command);

    if (creator)
    {
        in.unget();
        creator->createCommand(in);
        return true;
    }

    throw std::invalid_argument("Command not found!");
}
