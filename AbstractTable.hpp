#pragma once
#include <string>
#include <iostream>

#include <pqxx/pqxx>
#include <fmt/core.h>

#include "SqlCommands.hpp"

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
    pqxx::row virtual getElement(int id) = 0;

    /// @brief
    /// @param id
    void virtual removeElement(int id) = 0;
    /// @brief
    /// @param
    void virtual deleteTable() = 0;

    AbstractTable(const std::string &table);
    AbstractTable(const std::string &table, std::string &connection);
    virtual ~AbstractTable();

protected:
    void virtual performExecuteCommand(const std::string &command) = 0;
    std::string tableName;
    pqxx::connection connection;
};