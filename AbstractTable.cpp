#include "AbstractTable.hpp"

AbstractTable::AbstractTable(const std::string &table) : tableName{table} {}

void AbstractTable::insertElement(int id, const std::string &value)
{
   auto command = fmt::format(SqlCommands::insertElement, tableName, id, value);
   performExecuteCommand(command);
}
/// @brief
/// @param id
/// @param value
void AbstractTable::updateElement(int id, const std::string &value)
{
   auto command = fmt::format(SqlCommands::updateElement, tableName, value, id);
   performExecuteCommand(command);
}
/// @brief
/// @param id
/// @return
std::string AbstractTable::getElement(int id)
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

/// @brief
/// @param id
void AbstractTable::removeElement(int id) = 0
{
   auto command = fmt::format(SqlCommands::removeElement, tableName, id);
   performExecuteCommand(command);
}
/// @brief
/// @param 
void AbstractTable::deleteTable(const std::string &table)
{
   auto command = fmt::format(SqlCommands::removeElement, tableName, id);
   performExecuteCommand(command);
}

void AbstractTable::performExecuteCommand(const std::string &command)
{
    pqxx::work work(connection);
    work.exec(command.c_str());
    work.commit();
}