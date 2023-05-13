#include "Database.hpp"
#include <fmt/core.h>

Database::Database(std::string createTable) : connection(SqlCommands::startConnection.c_str()), work(connection)
{
    if (connection_is_open())
    {
        try
        {
            work.exec(createTable.c_str());
            work.commit()
        }
        catch (const std::exception& error)
        {
            std::cerr << error.what() << std::endl;
        }
    }
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
    work.commit();
    std::cout << command << " \n";
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::updateElement, id, value);
    work.exec(command.c_str());
    work.commit();
    std::cout << command << "\n";
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, id);
    try{
    /* Create a non-transactional object. */
    nontransaction nonTransactionalObject(connection);
    pqxx::result result {nonTransactionalObject.exec(command.c_str())};
    std::cout << command << "\n";
    return result[MTV_ROW::TEXT].as<std::string> ;
    }
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, id);
    work.exec(command.c_str());
    work.commit();
    std::cout << command << "\n";
}

void Database::deleteTable(std::string table)
{
    auto command = fmt::format(SqlCommands::deleteTable, table);
    work.exec(command.c_str());
    work.commit();
    std::cout << command << "\n";
}
