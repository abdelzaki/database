#pragma once
#include "AbstractTable.hpp"

class DocumentationTable : public AbstractTable
{
    friend class Database;

public:
    void insertElement(int id, const std::string &name, const std::string &date );

    void updateElement(int id, const std::string &name, const std::string &date);

    std::string getElement(int id);

    void removeElement(int id);

    void deleteTable();

    void performExecuteCommand(const std::string &command);

    virtual ~MtvTable();

private:
    DocumentationTable();
    std::string tableName;
    pqxx::connection connection;

};