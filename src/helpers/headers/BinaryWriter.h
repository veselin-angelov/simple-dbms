//
// Created by vesko on 11.01.23.
//

#ifndef DBMS_BINARYWRITER_H
#define DBMS_BINARYWRITER_H


class BinaryWriter
{
public:
    void write_string(std::ofstream &file, const std::string& data) const;
    void write_number(std::ofstream &file, const size_t data) const;
};


#endif //DBMS_BINARYWRITER_H
