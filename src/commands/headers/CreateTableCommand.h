//
// Created by vesko on 06.01.23.
//

#ifndef DBMS_CREATETABLECOMMAND_H
#define DBMS_CREATETABLECOMMAND_H


#include "../../structure/headers/Table.h"
#include "../../helpers/headers/BinaryWriter.h"
#include "Command.h"

class CreateTableCommand
{
private:
    static BinaryWriter writer;

public:
    explicit CreateTableCommand(std::istream &in);

private:
    void save_to_file(const Table &table) const;
    void create_data_files(const Table &table) const;

//    static void test_read(const std::string& name); // remove

};

class CreateTableCommandCreator : public CommandCreator
{
public:
    CreateTableCommandCreator();
    void createCommand(std::istream &in) const override;
};

#endif //DBMS_CREATETABLECOMMAND_H
