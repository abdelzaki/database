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
    #if (debug)
    std::cout << command << " \n";
    #endif
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::updateElement, id, value);
    work.exec(command.c_str());
    #if (debug)
    std::cout << command << " \n";
    #endif
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, id);
    work.exec(command.c_str());
    std::cout << command << "\n";
    #if (debug)
    std::cout << command << " \n";
    #endif
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, id);
    #if (debug)
    std::cout << command << " \n";
    #endif
}

void Database::deleteTable(std::string table)
{
    auto command = fmt::format(SqlCommands::deleteTable, table);
    #if (debug)
    std::cout << command << " \n";
    #endif
}
