#ifndef mtvTable
#define mtvtable

#pragma once
#include "abstractTable.hpp"

class MtvTable : public AbstractTable
{
    friend class Database;

public:
    void insertElement(int id, const std::string &value);

    void updateElement(int id, const std::string &value);

    pqxx::row getElement(int id);

    void removeElement(int id);

    void deleteTable();

    void performExecuteCommand(const std::string &command);

    virtual ~MtvTable();

private:
    MtvTable();
};

#endif