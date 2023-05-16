#include "AbstractTable.hpp"

AbstractTable::AbstractTable(const std::string &table) : tableName{table} {

}

AbstractTable::AbstractTable(const std::string &table, std::string &startConnection) : tableName{table}, connection(startConnection.c_str())
{
   std::cout << "table name" << tableName <<" \n";
}

void AbstractTable::insertElement(int id, const std::string &value){
      auto command = fmt::format(SqlCommands::insertElementBasic, tableName, id, value);
      performExecuteCommand(command);
      
}
/// @brief
/// @param id
/// @param value
void AbstractTable::updateElement(int id, const std::string &value)
{
   auto command = fmt::format(SqlCommands::updateElementBasic, tableName, value, id);
   performExecuteCommand(command);
}
/// @brief
/// @param id
/// @return
pqxx::row AbstractTable::getElement(int id)
{
   auto command = fmt::format(SqlCommands::findElementBasic, tableName, id);
   try
   {
      pqxx::work work(connection);
      pqxx::result result = work.exec(command.c_str());
      return result.at(0);
   }
   catch (const std::exception &error)
   {
      std::cerr << error.what() << std::endl;
     
   }
}

/// @brief
/// @param id
void AbstractTable::removeElement(int id)
{
   auto command = fmt::format(SqlCommands::removeElementBasic, tableName, id);
   performExecuteCommand(command);
}
/// @brief
/// @param
void AbstractTable::deleteTable()
{
   auto command = fmt::format(SqlCommands::deleteTableBasic, tableName);
   performExecuteCommand(command);
}

AbstractTable::~AbstractTable()
{
}

void AbstractTable::performExecuteCommand(const std::string &command)
{
   pqxx::work work(connection);
   work.exec(command.c_str());
   work.commit();

}