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
    void write_uchar(std::ofstream &file, const unsigned char data) const;
    void write_size_t(std::ofstream &file, const size_t data) const;
    void write_int(std::ofstream &file, const int data) const;
    void write_double(std::ofstream &file, const double data) const;
    void write_bool(std::ofstream &file, const bool data) const;
};


#endif //DBMS_BINARYWRITER_H
