#pragma once
#include "AbstractTable.hpp"

class DocumentationTable : public AbstractTable
{
    friend class Database;

public:
    void insertElement(int id, const std::string &name, const std::string &date);

    void updateElement(int id, const std::string &name, const std::string &date);

    pqxx::row getElement(int id) override;

    void removeElement(int id) override;

    void deleteTable() override;

    void performExecuteCommand(const std::string &command);

    virtual ~DocumentationTable();

private:
    DocumentationTable();
};