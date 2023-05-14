#include "Database.hpp"
#include <fmt/core.h>




Database::Database(const std::string&  command) :  connection(SqlCommands::startConnection.c_str()) 
{


    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
    }
    




Database& Database::getInstance()
{

    static Database instance{SqlCommands::createTable};

    return instance;
}

void Database::insertElement(int id, const std::string& value)
{
    auto command = fmt::format(SqlCommands::insertElement, id, value);
    performExecuteCommand(command);
}

void Database::updateElement(int id, const std::string& value)
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
    auto command = fmt::format(SqlCommands::removeElement, id);
    performExecuteCommand(command);
}

void Database::deleteTable(const std::string& table)
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
