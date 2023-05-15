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
    void performExecuteCommand(const std::string &command) = 0;

private:
    std::string tableName;
    qxx::connection connection;
    /// @brief
    /// @param command

};