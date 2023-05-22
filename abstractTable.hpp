#ifndef abstractTable
#define abstractTable
#pragma once

#include <string>
#include <set>
#include <map>
#include <pqxx/pqxx>

class AbstractTable
{
public:
    void virtual insertElement(int id, const std::string &value);
    /// @brief
    /// @param id
    /// @param value
    void virtual updateElement(int id, const std::string &value);
    /// @brief
    /// @param id
    /// @return
    std::map<std::string,std::string > virtual getElement(int id) = 0;

    /// @brief
    /// @param id
    void virtual removeElement(int id) = 0;
    /// @brief
    /// @param
    void virtual deleteTable() = 0;

    void virtual setTableRowElement(const std::string &element) = 0;
    void virtual setTableRowElement(const std::set<std::string> &elements) = 0;

    AbstractTable(const std::string &table);
    AbstractTable(const std::string &table, std::string &connection);
    virtual ~AbstractTable();

protected:
    std::string tableName;
    pqxx::connection connection;
    std::set<std::string> tableRowElements;
    void virtual performExecuteCommand(const std::string &command) = 0;
};

#endif