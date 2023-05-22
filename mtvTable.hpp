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

    std::map<std::string, std::string> virtual getElement(int id) override;

    void removeElement(int id) override;

    void deleteTable();

    virtual ~MtvTable();

      void virtual setTableRowElement(const std::string &element)override;
    void virtual setTableRowElement(const std::set<std::string> &elements) override;

protected:
    void performExecuteCommand(const std::string &command);
    MtvTable();
};

#endif