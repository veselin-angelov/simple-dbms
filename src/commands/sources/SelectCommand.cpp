//
// Created by vesko on 10.01.23.
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "../headers/SelectCommand.h"

SelectCommand::SelectCommand(std::istream &in)
{
    std::vector<std::string> column_names;
    std::string input;
    bool end = false;

    Filter filter;
    Order order;

    if (in.peek() == '*')
    {
        in.get(); // *
        in >> input; // FROM
        if (input != "FROM") throw std::runtime_error("Wrong command format!");
    }
    else
    {
//        TODO check for aggregates
        in >> input;
        while (input != "FROM")
        {
            if (input.back() == ',') input.pop_back();
            column_names.push_back(input);
            in >> input;
        }
    }

    in >> input;
    if (input.back() == ';')
    {
        end = true;
        input.pop_back();
    }

    Table table(input);

    if (!column_names.empty())
    {
        checkIfColumnsExist(column_names, table);
    }

    if (!end)
    {
        in >> input; // WHERE, ORDER

        if (input == "WHERE")
        {
            filter = handleWhereClause(in, table);

            if (in.peek() != ';')
            {
                in >> input;
                if (input != "ORDER") throw std::runtime_error("Wrong format select command on ORDER clause!");
                order = handleOrderClause(in, table);
            }
        } else if (input == "ORDER")
        {
            order = handleOrderClause(in, table);
        } else throw std::runtime_error("Wrong format select command on WHERE clause!");
    }

    select_.select(table, column_names, filter, order);
    std::cout << "Selected." << std::endl;
}

void SelectCommand::checkIfColumnsExist(std::vector<std::string> &column_names, Table &table) const
{
    for (auto &column_name: column_names)
    {
        auto it = std::find_if(
                table.columns.begin(),
                table.columns.end(),
                [&column_name](Column *&col)
                { return col->getName() == column_name; }
        );

        if (it == table.columns.end())
        {
            throw std::runtime_error("Column with name: \"" + column_name + "\" not found!");
        }
    }
}

Filter SelectCommand::handleWhereClause(std::istream &in, Table &table) const
{
    Filter filter;

    while (std::isspace(in.peek())) in.get();

    while (!Operator::isOperator(in.peek()))
    {
        filter.column += in.get();
    }

    size_t index = 0;
    while (Operator::isOperator(in.peek()))
    {
        if (index > 1) throw std::runtime_error("Invalid operator!");
        filter.op.value += in.get();
        index++;
    }
    Operator::validateOperator(filter.op);

    in >> filter.value;

    if (filter.value.back() == ';')
    {
        filter.value.pop_back();
        in.unget();
    }

    return filter;
}

Order SelectCommand::handleOrderClause(std::istream &in, Table &table) const
{
    Order order;

    std::string input;

    in >> input;
    if (input != "BY") throw std::runtime_error("Missing BY in order!");

    in >> order.column_name;

    in >> input;
    if (input.back() == ';') input.pop_back();

    if (input == "ASC") order.ordering = Ordering::ASC;
    else if (input == "DESC") order.ordering = Ordering::DESC;
    else throw std::runtime_error("Missing ASC/DESC in clause!");

    return order;
}

SelectCommandCreator::SelectCommandCreator() : CommandCreator("SELECT")
{}

void SelectCommandCreator::createCommand(std::istream &in) const
{
    delete new SelectCommand(in);
}

static SelectCommandCreator __;
Select SelectCommand::select_ = Select();
