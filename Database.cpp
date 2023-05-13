#include "Database.hpp"
#include <fmt/core.h>

Database::Database(std::string createTable) : conn(DatabaseCommands::startConnection.c_str()),work(conn)
{
     work.exec(createTable.c_str());

    //std::cout << DatabaseCommands::createTable;
}

Database &Database::getInstance()
{

    static Database instance{DatabaseCommands::createTable};
    return instance;
}

void Database::insertElement(int id, std::string value)
{   
    auto command = fmt::format(DatabaseCommands::insertElement, id, value);
    work.exec(command.c_str());
    std::cout << command << " \n";
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(DatabaseCommands::updateElement, id, value);
    std::cout << command << "\n";
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(DatabaseCommands::findElement, id);
    std::cout << command << "\n";
    return command;
}

void Database::removeElement(int id)
{
    auto command = fmt::format(DatabaseCommands::removeElement, id);
     std::cout << command << "\n";
}

void Database::deleteTable(std::string table)
{
    auto command = fmt::format(DatabaseCommands::deleteTable, table);
     std::cout << command << "\n";
}
