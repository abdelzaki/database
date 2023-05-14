#include "Database.hpp"
#include <fmt/core.h>

Database::Database(std::string createTable) : connection(SqlCommands::startConnection.c_str())
{
    if (connection.is_open())
    {
        try
        {
            auto command = createTable.c_str();
            pqxx::work work(connection);
            work.exec(createTable.c_str());
            work.commit();
            std::cout << command << " \n";
        }
        catch (const std::exception &error)
        {
            std::cerr << error.what() << " 1" << std::endl;
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
    std::cout << "beofre insert  \n";
    auto command = fmt::format(SqlCommands::insertElement, id, value);
    performExecuteCommand(command.c_str());
    std::cout << command << " \n";
}

void Database::updateElement(int id, std::string value)
{
    auto command = fmt::format(SqlCommands::updateElement, value, id);
    performExecuteCommand(command.c_str());
    std::cout << command << "\n";
}

std::string Database::getElement(int id)
{
    auto command = fmt::format(SqlCommands::findElement, id);
    try
    {
        /* Create a non-transactional object. */
        // pqxx::nontransaction nonTransactionalObject(connection);
        // pqxx::result result {nonTransactionalObject.exec(command.c_str())};
        pqxx::work work(connection);
        pqxx::result result = work.exec(command.c_str());
        std::cout << command << "\n";
        // static_cast<int>(MTV_ROW::TEXT).as<std::string>
        return result.at(0)["TEXT"].c_str();
        // return "hi";
    }
    catch (const std::exception &error)
    {
        std::cerr << error.what() << " 2" << std::endl;
        return "no found";
    }
}

void Database::removeElement(int id)
{
    auto command = fmt::format(SqlCommands::removeElement, id);
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
    std::cout << command << "\n";
}

void Database::deleteTable(std::string table)
{
    auto command = fmt::format(SqlCommands::deleteTable, table);
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
    std::cout << command << "\n";
}

void Database::performExecuteCommand(std::string command){
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();

}
