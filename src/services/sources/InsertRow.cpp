//
// Created by vesko on 15.01.23.
//

#include "../headers/InsertRow.h"

void InsertRow::insert(std::map<std::string, std::string> &values, Table &table) const
{
    std::ofstream table_file_data(table.path + ".data", std::ios::binary | std::ios::ate | std::ios::in);

    if (!table_file_data.is_open()) throw std::runtime_error("Opening table file failed!");
    
    table_file_data.seekp(table.valid_position);

    if (!table_file_data.good()) throw std::runtime_error("Seeking failed!");

    for (auto &column : table.columns)
    {
        column->getType()->writeToFile(
            writer,
            table_file_data, 
            std::pair<const std::string, const std::string>(column->getName(), values[column->getName()]), 
            table.path + ".data");
    }

    table.valid_position = table_file_data.tellp();

    std::ofstream table_file(table.path, std::ios::binary | std::ios::ate | std::ios::in); // otherwise it truncates

    if (!table_file.is_open()) throw std::runtime_error("Opening table file failed!");
    
    table_file.seekp(std::ios::beg);

    if (!table_file.good()) throw std::runtime_error("Seeking failed!");

    writer.write_size_t(table_file, table.valid_position);
}

BinaryWriter InsertRow::writer = BinaryWriter();
