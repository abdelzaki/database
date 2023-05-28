
#include <iostream>
#include <fmt/core.h>
#include "sql_commands.hpp"
#include "abstract_table.hpp"
AbstractTable::AbstractTable(const std::string &table, std::string &startConnection) : TableName{table}, Connection(startConnection.c_str()) 
{

}

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

std::map<std::string, std::string> AbstractTable::getElement(std::string attribute, std::string compare, std::string value)
{
   auto command = fmt::format(sql_commands::findElement, TableName, attribute, compare, value);
   executeGetCommand(command)

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

 elementsVector AbstractTable::executeGetCommand(const std::string &command)
{
   elementsVector elements;
   try
   {
      pqxx::work work(Connection);
      pqxx::result result = work.exec(command.c_str());

      for (auto const &key : TableRowElements)
      {
         elements[key] = result.at(0)[key].c_str();
      }
   }
   catch (const std::exception &error)
   {
      std::cerr << error.what() << std::endl;
   }
   return elements;
}

void AbstractTable::setTableRowElement(const std::string &element)
{
   TableRowElements.insert(element);
}
void AbstractTable::setTableRowElement(const std::set<std::string> &elements)
{
   TableRowElements = elements;
}



AbstractTable::~AbstractTable() {}