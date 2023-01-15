//
// Created by vesko on 09.01.23.
//

#include <iostream>
#include "../headers/InsertIntoCommand.h"
#include "../../services/headers/Select.h"

InsertIntoCommand::InsertIntoCommand(std::istream &in)
{
    std::string table_name;
    in >> table_name;

    Table table(table_name);

    do
    {
    } while (in.get() != '(');

    char c;
    std::string input;
    size_t index = 1;

    std::map<std::string, std::string> values; // not sure about this

    for (auto &column : table.columns)
    {
        input = column->getType()->readValue(column->getName(), in);

        values[column->getName()] = input;

        c = in.get();
        if ((c == ';' || c == ')') && index != table.columns.size())
            throw std::runtime_error("Wrong insert command!");

        while (std::isspace(in.peek()))
        {
            in.get();
        }

        index++;
    }

    if (table.primary_key)
    {
        Select select1;
        std::ifstream in(table.path + ".data", std::ios::binary);

        if (!in.is_open()) throw std::runtime_error("Could not open file!");

        Operator op("=");
        Filter filter(table.primary_key->getName(), op, values[table.primary_key->getName()]);
        std::vector<Column*> selected_columns;
        selected_columns.push_back(table.primary_key);

        auto rows = select1.get_rows(table, selected_columns, in, filter);

        if (!rows.empty()) throw std::runtime_error("Primary key exists!");
    }


    insertRow.insert(values, table);
    std::cout << "Record inserted." << std::endl;
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
