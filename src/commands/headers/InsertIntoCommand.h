//
// Created by vesko on 09.01.23.
//

#ifndef DBMS_INSERTINTOCOMMAND_H
#define DBMS_INSERTINTOCOMMAND_H


#include "Command.h"
#include "../../helpers/headers/BinaryWriter.h"
#include "../../services/headers/InsertRow.h"

class InsertIntoCommand
{
private:
    static InsertRow insertRow;

public:
    explicit InsertIntoCommand(std::istream &in);
};

class InsertIntoCommandCreator : public CommandCreator
{
public:
    InsertIntoCommandCreator();
    void createCommand(std::istream &in) const override;
};

#endif //DBMS_INSERTINTOCOMMAND_H
