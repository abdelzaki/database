#include "Database.hpp"
#include <fmt/core.h>

Database::Database(const std::string&  command) : connection(SqlCommands::startConnection.c_str())
{
    createConenction(command)
}

void Database::createConenction(const std::string&  command)
{
    if (connection.is_open())
    {
        try
        {
            auto command = createTable.c_str();
            performExecuteCommand(createTable);
        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << std::endl;
        }
    }
}

Database &Database::getInstance()
{

    static Database instance{SqlCommands::createTable};
    if (!connection.is_open())
        createConenction(SqlCommands::createTable) return instance;
}

void Database::insertElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::insertElement, id, value);
    performExecuteCommand(command);
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::updateElement, value, id);
    performExecuteCommand(command);
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, id);
    try
    {
        pqxx::work work(connection);
        pqxx::result result = work.exec(command.c_str());
        std::cout << command << "\n";
        return result.at(0)["NAME"].c_str();
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
    }
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, id);
    performExecuteCommand(command);
}

void Database::deleteTable(std::string table)
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
