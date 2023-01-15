//
// Created by vesko on 11.01.23.
//

#ifndef DBMS_BINARYWRITER_H
#define DBMS_BINARYWRITER_H

#include <fstream>
#include <string>

class BinaryWriter
{
public:
    void write_string(std::ofstream &file, const std::string& data) const;
    void write_number(std::ofstream &file, const long long data) const;
};


#endif //DBMS_BINARYWRITER_H
