#include <iostream>
#include <limits>
#include "commands/headers/CreateTableCommand.h"
#include "factories/headers/CommandFactory.h"

int main()
{
//    std::ifstream createCommand("test.txt");
//
//    if (!createCommand.is_open()) throw std::runtime_error("cannot open");

    bool result;

    while (true)
    {
        try
        {
            result = CommandFactory::getFactory().createCommand(std::cin);
            if (!result) break;
//            std::cin.clear();
//            std::cin.ignore(1024, '\n');
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
