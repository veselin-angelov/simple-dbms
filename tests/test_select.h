//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_TEST_SELECT_H
#define SIMPLE_DBMS_TEST_SELECT_H

#include <sstream>
#include "doctest.h"
#include "../src/factories/headers/CommandFactory.h"

TEST_CASE("Test select *")
{
    system("make remove-db");
    std::stringstream createCommand;
    createCommand << "CREATE TABLE students (name string, fn int, group int, is_active bool, sdp_grade double) PRIMARY KEY fn;";
    CHECK_NOTHROW(CommandFactory::getFactory().createCommand(createCommand));

//    createCommand.flush();

    std::stringstream createCommand1;
    createCommand1 << "SELECT * FROM students;";
    CHECK_NOTHROW(CommandFactory::getFactory().createCommand(createCommand));

    system("make remove-db");
}

//TEST_CASE("Test select * with where")
//{
//    system("make remove-db");
//    std::stringstream createCommand;
//    createCommand << "CREATE TABLE students (name string, fn int, group int, is_active bool, sdp_grade double) PRIMARY KEY fn;";
//    CHECK_NOTHROW(CommandFactory::getFactory().createCommand(createCommand));
//
//    createCommand.flush();
//
//    createCommand << "SELECT * FROM students WHERE group=2;";
//    CHECK_NOTHROW(CommandFactory::getFactory().createCommand(createCommand));
//
//    system("make remove-db");
//}

#endif //SIMPLE_DBMS_TEST_SELECT_H
