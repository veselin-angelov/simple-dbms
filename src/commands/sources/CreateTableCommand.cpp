//
// Created by vesko on 06.01.23.
//

// #include <iostream>
#include <iostream>
#include "../headers/CreateTableCommand.h"
#include "../../structure/headers/Table.h"
#include "../../constants.h"
#include "../../factories/headers/TypeFactory.h"

CreateTableCommand::CreateTableCommand(std::istream &in)
{
    Table table;

    in >> table.name;
    table.path = DB_PATH + table.name;

    while (in.get() != '(');

    std::string column_name;
    Type* column_type;
    Column* column;

    while (true)
    {
        in >> column_name;

        column_type = TypeFactory::getFactory().createType(in);
        column = new Column(column_name, column_type);
        table.columns.push_back(column);

        if (in.peek() == ')')
        {
            in.get();
            break;
        }
    }

    if (in.peek() == ';')
    {
        createTable.create(table);
        return;
    }

    std::string pk;
    in >> pk;
    if (pk != "PRIMARY") throw std::invalid_argument("PRIMARY KEY expected!");
    in >> pk;
    if (pk != "KEY") throw std::invalid_argument("PRIMARY KEY expected!");

    in >> pk;

    if (pk.back() != ';') throw std::invalid_argument("Semicolon ';' expected at the end!");

    pk.pop_back();
    table.primary_key = table.getColumnByName(pk);

    if (!table.primary_key) throw std::invalid_argument("Primary column " + pk + " is one of the columns!");

    createTable.create(table);
    std::cout << "Table \"" + table.name + "\" created." << std::endl;
}

CreateTableCommandCreator::CreateTableCommandCreator() : CommandCreator("CREATE TABLE")
{}

void CreateTableCommandCreator::createCommand(std::istream &in) const
{
    delete new CreateTableCommand(in);
}

static CreateTableCommandCreator __;
CreateTable CreateTableCommand::createTable = CreateTable();
