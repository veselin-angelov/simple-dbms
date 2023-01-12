//
// Created by vesko on 11.01.23.
//

#ifndef DBMS_BINARYREADER_H
#define DBMS_BINARYREADER_H


#include <string>

class BinaryReader
{
public:
    std::string read_string(std::ifstream &file) const;
    size_t read_number(std::ifstream &file) const;
};


#endif //DBMS_BINARYREADER_H
