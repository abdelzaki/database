#pragma once
#include <string>
#include <iostream>

#include <pqxx/pqxx>
#include <fmt/core.h>

#include "SqlCommands.hpp"

class AbstractTable
{
public:
    AbstractTable(const std::string &table);
    AbstractTable(const std::string &table, std::string& connection);
    void virtual insertElement(int id, const std::string &value) = 0;
    /// @brief
    /// @param id
    /// @param value
    void virtual updateElement(int id, const std::string &value) = 0;
    /// @brief
    /// @param id
    /// @return
    std::string virtual getElement(int id) = 0;

    /// @brief
    /// @param id
    void virtual removeElement(int id) = 0;
    /// @brief
    /// @param taböe
    void virtual deleteTable(const std::string &table) = 0;
    virtual ~AbstractTable();

protected:
    void virtual performExecuteCommand(const std::string &command) = 0;
    std::string tableName;
    pqxx::connection connection;
    

};