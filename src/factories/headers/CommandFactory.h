//
// Created by vesko on 09.01.23.
//

#ifndef DBMS_COMMANDFACTORY_H
#define DBMS_COMMANDFACTORY_H


#include <vector>
#include "../../commands/headers/Command.h"

class CommandFactory
{
private:
    std::vector<const CommandCreator*> creators;

private:
    const CommandCreator* getCreator(const std::string& key) const;

private:
    CommandFactory() = default;
    ~CommandFactory() = default;

public:
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;

public:
    static CommandFactory& getFactory();
    void registerCommand(const CommandCreator* creator);
    bool createCommand(std::istream &in);
};


#endif //DBMS_COMMANDFACTORY_H
