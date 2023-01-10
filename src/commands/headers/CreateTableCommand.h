//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_CREATETABLECOMMAND_H
#define DBMS_CREATETABLECOMMAND_H


#include "../../structure/headers/Table.h"
#include "Command.h"

class CreateTableCommand
{
public:
    explicit CreateTableCommand(std::istream &in);

private:
    static void save_to_file(const Table &table);
    static void create_data_files(const Table &table);
    static void write_string(std::ofstream &file, const std::string& data); // TODO maybe extract to another file

    static void test_read(const std::string& name); // remove

};

class CreateTableCommandCreator : public CommandCreator
{
public:
    CreateTableCommandCreator();
    void createCommand(std::istream &in) const override;
};

#endif //DBMS_CREATETABLECOMMAND_H
