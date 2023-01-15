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
    unsigned char read_uchar(std::ifstream &file) const;
    std::size_t read_size_t(std::ifstream &file) const;
    int read_int(std::ifstream &file) const;
    double read_double(std::ifstream &file) const;
    bool read_bool(std::ifstream &file) const;
};


#endif //DBMS_BINARYREADER_H
