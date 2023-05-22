
#include <iostream>
#include <fmt/core.h>
#include "sqlCommands.hpp"
#include "abstractTable.hpp"

// AbstractTable::AbstractTable(const std::string &table) : tableName{table} {}

AbstractTable::AbstractTable(const std::string &table, std::string &startConnection) : tableName{table}, connection(startConnection.c_str()) {}

void AbstractTable::insertElement(int id, const std::string &value)
{
   auto command = fmt::format(sql_commands::clearTableinsertElementMtv, tableName, id, value);
   performExecuteCommand(command);
}

void AbstractTable::updateElement(int id, const std::string &value)
{
   auto command = fmt::format(sql_commands::updateElementMtv, tableName, value, id);
   performExecuteCommand(command);
}

std::map<std::string, std::string> AbstractTable::getElement(int id)
{
   auto command = fmt::format(sql_commands::findElement, tableName, id);
   try
   {
      pqxx::work work(connection);
      pqxx::result result = work.exec(command.c_str());
      std::map<std::string, std::string> elements;
      for (auto const &key : tableRowElements)
      {
         elements[key] = result.at(0)[key].c_str();
      }

      return elements;
   }
   catch (const std::exception &error)
   {
      std::cerr << error.what() << std::endl;
   }
}

void AbstractTable::removeElement(int id)
{
   auto command = fmt::format(sql_commands::removeElement, tableName, id);
   performExecuteCommand(command);
}

void AbstractTable::clearTable()
{
   auto command = fmt::format(sql_commands::clearTable, tableName);
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

void AbstractTable::setTableRowElement(const std::string &element)
{
   tableRowElements.insert(element);
}
void AbstractTable::setTableRowElement(const std::set<std::string> &elements)
{
   tableRowElements = elements;
}