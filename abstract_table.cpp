
#include <iostream>
#include <fmt/core.h>
#include "sql_commands.hpp"
#include "abstract_table.hpp"

typedef std::map<std::string, std::string> elementAsMap;
typedef std::vector<elementAsMap> vectorOfElementsAsMap;

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

vectorOfElementsAsMap AbstractTable::getElements(std::string attribute, std::string compare, std::string value)
{
   auto command = fmt::format(sql_commands::getElement, TableName, attribute, compare, value);
   return executeGetCommand(command);
}

int AbstractTable::getMinAttribute(std::string attribute)

{
   auto command = fmt::format(sql_commands::minAttribute, attribute, TableName);
   pqxx::work work(Connection);
   pqxx::result result = work.exec(command.c_str());
   if (result[0][0].is_null())
      return 0;
   return result[0][0].as<int>();
}

int AbstractTable::getMaxAttribute(std::string attribute)
{
   auto command = fmt::format(sql_commands::maxAttribute, attribute, TableName);
   pqxx::work work(Connection);
   pqxx::result result = work.exec(command.c_str());
   if (result[0][0].is_null())
      return 0;
   return result[0][0].as<int>();
}

int AbstractTable::getTableSize()
{
   auto command = fmt::format(sql_commands::getAllElements, TableName);
   return executeCommand(command).size();
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

pqxx::result AbstractTable::executeCommand(const std::string &command)
{
   pqxx::work work(Connection);
   pqxx::result result = work.exec(command.c_str());
   work.commit();
   return result;
}

vectorOfElementsAsMap AbstractTable::executeGetCommand(const std::string &command)
{
   vectorOfElementsAsMap elements;
   elementAsMap element;
   try
   {
      pqxx::work work(Connection);
      pqxx::result result = work.exec(command.c_str());
      for (pqxx::result::const_iterator row = result.begin(); row != result.end(); ++row)
      {
         for (auto const &key : TableRowElements)
         {
            element[key] = row[key].c_str();
         }
         elements.push_back(element);
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