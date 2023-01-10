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

void CreateTableCommand::save_to_file(const Table &table)
{
    std::ifstream f(table.path);
    if (f.good()) throw std::invalid_argument("Table " + table.name + " already exists!");

    std::ofstream table_file(table.path, std::ios::binary);

    if (!table_file.is_open()) throw std::runtime_error("Opening table file failed!");

    table_file.write(reinterpret_cast<const char*>(&table.valid_position), sizeof(table.valid_position));

    write_string(table_file, table.name);

    size_t size = table.columns.size();
    table_file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (auto &column: table.columns)
    {
        write_string(table_file, column->getName());
        write_string(table_file, column->getType()->name());
    }

    if (table.primary_key) write_string(table_file, table.primary_key->getName());

    create_data_files(table);

    table.print();
}

void CreateTableCommand::create_data_files(const Table &table)
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

void CreateTableCommand::write_string(std::ofstream& file, const std::string &data)
{
    size_t size = data.size();
    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    file.write(reinterpret_cast<const char*>(data.c_str()), size);
}

void CreateTableCommand::test_read(const std::string& name)
{
    Table table;

    std::ifstream table_file(DB_PATH + name, std::ios::binary);

//    table_file.read((char *) &table, sizeof(Table));
    size_t size;
    table_file.read(reinterpret_cast<char*>(&size), sizeof(size));
    char* input = new char[size + 1];
    table_file.read(input, size);
    input[size] = '\0';
    table.name = input;
    delete[] input;

    table.print();

}

CreateTableCommandCreator::CreateTableCommandCreator() : CommandCreator("CREATE TABLE")
{}

void CreateTableCommandCreator::createCommand(std::istream &in) const
{
    delete new CreateTableCommand(in);
//    delete cmd;
}

static CreateTableCommandCreator __;
