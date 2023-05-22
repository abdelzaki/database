#ifndef documentationTable
#define documentationTable

#pragma once
#include <string>

#include "abstractTable.hpp"

class DocumentationTable : public AbstractTable
{
    friend class Database;

public:
    void insertElement(int id, const std::string &name, const std::string &date);

    void updateElement(int id, const std::string &name, const std::string &date);

    std::map<std::string , std::string> virtual getElement(int id) override;

    void removeElement(int id) override;

    void deleteTable() override;

    void virtual setTableRowElement(const std::string &element)override;
    void virtual setTableRowElement(const std::set<std::string> &elements) override;

    virtual ~DocumentationTable();

protected:
    void performExecuteCommand(const std::string &command);
    DocumentationTable();
};

#endif