//
// Created by vesko on 09.01.23.
//

#ifndef DBMS_COMMAND_H
#define DBMS_COMMAND_H


#include <string>
#include <istream>

class Command
{};

class CommandCreator
{
private:
    const std::string key;

public:
    explicit CommandCreator(const std::string &key);
    virtual ~CommandCreator() = default;
    CommandCreator(const CommandCreator&) = delete;
    CommandCreator& operator=(const CommandCreator&) = delete;

public:
    const std::string &getKey() const;
    virtual void createCommand(std::istream &in) const = 0;
};


#endif //DBMS_COMMAND_H
