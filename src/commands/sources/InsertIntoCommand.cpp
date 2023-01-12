//
// Created by vesko on 09.01.23.
//

#include "../headers/InsertIntoCommand.h"
#include "../../structure/headers/Table.h"

InsertIntoCommand::InsertIntoCommand(std::istream &in)
{
// TODO load Table structure, then insert row
    std::string table_name;
    in >> table_name;

    Table table(table_name);

//    TODO build values map or Row object

    table.print();

//    if (table.primary_key) // TODO check if primary key exists if true => check if the value exists

}

InsertIntoCommandCreator::InsertIntoCommandCreator() : CommandCreator("INSERT INTO")
{}

void InsertIntoCommandCreator::createCommand(std::istream &in) const
{
    delete new InsertIntoCommand(in);
}

static InsertIntoCommandCreator __;
BinaryWriter InsertIntoCommand::writer = BinaryWriter();
