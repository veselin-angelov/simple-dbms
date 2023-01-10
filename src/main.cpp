#include <iostream>
#include <sstream>
#include "commands/headers/CreateTableCommand.h"
#include "factories/headers/CommandFactory.h"

int main()
{
    std::stringstream createCommand;
//    createCommand << "CREATE TABLE students (name string, fn int, group int, sdp_grade double) PRIMARY KEY fn;";
    createCommand << "CREATE TABLE students (name string, fn int, group int, sdp_grade double);";
//    createCommand << "students (name string, fn int, group int, sdp_grade double) PRIMARY KEY fn;";
    try
    {
//        CreateTableCommand::create(createCommand);
        CommandFactory::getFactory().createCommand(createCommand);

//        CreateTableCommand::test_read("students");
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    return 0;
}