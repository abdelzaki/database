#pragma once
#ifndef __Database__
#define __Database__

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "SqlCommands.hpp"

/// @brief
class Database
{

public:
    /// @brief
    /// @return
    static Database &getInstance();
    /// @brief
    /// @param id
    /// @param value
    void insertElement(int id, const std::string &value);
    /// @brief
    /// @param id
    /// @param value
    void updateElement(int id, const std::string &value);
    /// @brief
    /// @param id
    /// @return
    std::string getElement(int id);

    /// @brief
    /// @param id
    void removeElement(int id);
    /// @brief
    /// @param taböe
    void deleteTable(const std::string &table);

private:
    pqxx::connection connectionMtv_1;
     pqxx::connection connectionMtv_2
    /// @brief
    /// @param
    Database(const std::string &command);
    /// @brief
    /// @param command
    void performExecuteCommand(const std::string &command);


    std::string tableName;

    // Delete copy and move operator also copy and move constructor to be able to implement singelton
    Database(Database &) = delete;
    Database(Database &&) = delete;
    Database &operator=(Database const &) = delete;
    Database &operator=(Database const &&) = delete;
};

#endif