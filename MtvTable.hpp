#pragma once
#include "AbstractTable.hpp"

class MtvTable : public AbstractTable
{
    friend class Database;

public:
    void insertElement(int id, const std::string &value);

    void updateElement(int id, const std::string &value);

    std::string getElement(int id);

    void removeElement(int id);

    void deleteTable(const std::string &table);

    void performExecuteCommand(const std::string &command);

    virtual ~MtvTable();

private:
    MtvTable();
     std::string tableName;;
};