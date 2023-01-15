//
// Created by vesko on 09.01.23.
//

#include "../headers/InsertIntoCommand.h"
#include "../../structure/headers/Table.h"

InsertIntoCommand::InsertIntoCommand(std::istream &in)
{
    std::string table_name;
    in >> table_name;

    Table table(table_name);

    do
    {
    } while (in.get() != '(');

    std::string input;
    size_t index = 0;

    std::map<std::string, std::string> values; // not sure about this

    for (auto &column : table.columns)
    {
        input = column->getType()->readValue(column->getName(), in);

        values[column->getName()] = input;

        if (in.get() == ';' && index != table.columns.size())
            throw std::runtime_error("Wrong number of values");

        while (std::isspace(in.peek()))
        {
            in.get();
        }

        index++;
    }

    //    if (table.primary_key) // TODO check if primary key exists if true => check if the value exists

    insertRow.insert(values, table);
}

InsertIntoCommandCreator::InsertIntoCommandCreator() : CommandCreator("INSERT INTO")
{
}

void InsertIntoCommandCreator::createCommand(std::istream &in) const
{
    delete new InsertIntoCommand(in);
}

static InsertIntoCommandCreator __;
InsertRow InsertIntoCommand::insertRow = InsertRow();
