TableName
#include <iostream>
#include <fmt/core.h>
#include "sql_commands.hpp"
#include "abstract_table.hpp"

AbstractTable::AbstractTable(const std::string &table, std::string &startConnection) : TableName{table}, Connection(startConnection.c_str()) {}

void AbstractTable::insertElement(int id, const std::string &value)
{
   auto command = fmt::format(sql_commands::insertElementMtv, TableName, id, value);
   executeCommand(command);
}

void AbstractTable::updateElement(int id, const std::string &value)
{
   auto command = fmt::format(sql_commands::updateElementMtv, TableName, value, id);
   executeCommand(command);
}

std::map<std::string, std::string> AbstractTable::getElement(int id)
{
   auto command = fmt::format(sql_commands::findElement, TableName, id);
   try
   {
      pqxx::work work(Connection);
      pqxx::result result = work.exec(command.c_str());
      std::map<std::string, std::string> elements;
      for (auto const &key : TableRowElements)
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
   auto command = fmt::format(sql_commands::removeElement, TableName, id);
   executeCommand(command);
}

void AbstractTable::clearTable()
{
   auto command = fmt::format(sql_commands::clearTable, TableName);
   executeCommand(command);
}

void AbstractTable::executeCommand(const std::string &command)
{
   pqxx::work work(Connection);
   work.exec(command.c_str());
   work.commit();
}

void AbstractTable::setTableRowElement(const std::string &element)
{
   TableRowElements.insert(element);
}
void AbstractTable::setTableRowElement(const std::set<std::string> &elements)
{
   tableRowElements = elements;
}

AbstractTable::~AbstractTable() {}