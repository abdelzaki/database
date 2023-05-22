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

    std::map<std::string key, std::string value> virtual getElement(int id) override;

    void removeElement(int id) override;

    void deleteTable();

    virtual ~MtvTable();

protected:
    void performExecuteCommand(const std::string &command);
    MtvTable();
};

#endif