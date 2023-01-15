#include <iostream>
#include "commands/headers/CreateTableCommand.h"
#include "factories/headers/CommandFactory.h"

int main()
{
    std::ifstream createCommand("test.txt");

    if (!createCommand.is_open()) throw std::runtime_error("cannot open");

    try
    {
        CommandFactory::getFactory().createCommand(createCommand);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
