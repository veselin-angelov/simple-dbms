//
// Created by vesko on 06.01.23.
//

#include <fstream>
#include <iostream> // TODO remove
#include "../headers/CreateTableCommand.h"
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
        save_to_file(table);
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

    if (!table.primary_key) throw std::invalid_argument("Primary key " + pk + " is one of the columns!");

    save_to_file(table);
}

void CreateTableCommand::save_to_file(const Table &table) const
{
    std::ifstream f(table.path);
    if (f.good()) throw std::invalid_argument("Table " + table.name + " already exists!");

    std::ofstream table_file(table.path, std::ios::binary);

    if (!table_file.is_open()) throw std::runtime_error("Opening table file failed!");

    writer.write_number(table_file, table.valid_position);

    size_t size = table.columns.size();
    writer.write_number(table_file, size);

    for (auto &column: table.columns)
    {
        writer.write_string(table_file, column->getName());
        writer.write_string(table_file, column->getType()->name());
    }

    if (table.primary_key) writer.write_string(table_file, table.primary_key->getName());

    create_data_files(table);

    table.print();
}

void CreateTableCommand::create_data_files(const Table &table) const
{
    std::ofstream table_data_file(table.path + ".data", std::ios::binary);

    std::ofstream table_type_file;
    for (auto &column: table.columns)
    {
        if (column->getType()->name() == "string")
        {
            table_type_file.open(table.path + ".data." + column->getName(), std::ios::binary);
            table_type_file.close();
        }
    }
}

CreateTableCommandCreator::CreateTableCommandCreator() : CommandCreator("CREATE TABLE")
{}

void CreateTableCommandCreator::createCommand(std::istream &in) const
{
    delete new CreateTableCommand(in);
}

static CreateTableCommandCreator __;
BinaryWriter CreateTableCommand::writer = BinaryWriter();
