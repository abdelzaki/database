#include "Database.hpp"
#include <fmt/core.h>

Database::Database(std::string createTable) : connection(SqlCommands::startConnection.c_str()), work(connection)
{
    work.exec(createTable.c_str());

}

Database &Database::getInstance()
{

    static Database instance{SqlCommands::createTable};
    return instance;
}

void Database::insertElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::insertElement, id, value);
    work.exec(command.c_str());
    std::cout << command << " \n";
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::updateElement, id, value);
    std::cout << command << "\n";
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, id);
    std::cout << command << "\n";
    return command;
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, id);
    std::cout << command << "\n";
}

void Database::deleteTable(std::string table)
{
    auto command = fmt::format(SqlCommands::deleteTable, table);
    std::cout << command << "\n";
}
