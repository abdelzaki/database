#include "Database.hpp"
#include <fmt/core.h>

Database::Database(const std::string &command, const std::string& table) : connection(SqlCommands::startConnection.c_str())
{
    tableName = table;
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
}

Database &Database::getInstanceMtv_1()
{       
   
    std::string table = "tablex";
    auto command = fmt::format(SqlCommands::createTable, table);
    static Database instance_1{command, table};

    return instance_1;
}
Database &Database::getInstanceMtv_2()
{   std::string table = "tabley";
  
     auto command = fmt::format(SqlCommands::createTable, table);

    static Database instance_2{command, table};

    return instance_2;
}

void Database::insertElement(int id, const std::string &value)
{
    auto command = fmt::format(SqlCommands::insertElement, tableName, id, value);
    performExecuteCommand(command);
}

void Database::updateElement(int id, const std::string &value)
{
    auto command = fmt::format(SqlCommands::updateElement, tableName, value, id);
    performExecuteCommand(command);
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, tableName, id);
    try
    {
        pqxx::work work(connection);
        pqxx::result result = work.exec(command.c_str());

        return result.at(0)["NAME"].c_str();
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        return "NULL";
    }
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, tableName, id);
    performExecuteCommand(command);
}

void Database::deleteTable(const std::string &table)
{
    auto command = fmt::format(SqlCommands::deleteTable, table);
    performExecuteCommand(command);
}

void Database::performExecuteCommand(const std::string &command)
{
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
}
