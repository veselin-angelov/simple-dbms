//
// Created by vesko on 15.01.23.
//

#ifndef SIMPLE_DBMS_TEST_CREATE_H
#define SIMPLE_DBMS_TEST_CREATE_H


#include <sstream>
#include "doctest.h"
#include "../src/factories/headers/CommandFactory.h"

TEST_CASE("Test create")
{
    system("make remove-db");
    std::stringstream createCommand;
    createCommand << "CREATE TABLE students (name string, fn int, group int, is_active bool, sdp_grade double) PRIMARY KEY fn;";
    CHECK_NOTHROW(CommandFactory::getFactory().createCommand(createCommand));
    system("make remove-db");
}

#endif //SIMPLE_DBMS_TEST_CREATE_H
