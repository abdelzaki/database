
#include <iostream>
#include <sstream>

#include <fmt/core.h>
#include <pqxx/pqxx>

#include "sql_commands.hpp"
#include "documentation_table.hpp"

typedef std::map<std::string, std::string> elementAsMap;
typedef std::vector<elementAsMap> vectorOfElementsAsMap;

DocumentationTable::DocumentationTable(std::string connectionData) : AbstractTable("Documentation", connectionData)
{
    pqxx::work work(Connection);
    auto command = fmt::format(sql_commands::createTableDocumentation, TableName);
    work.exec(command.c_str());
    work.commit();
}

void DocumentationTable::insertElement(const std::string &date)
{
    int id = getMaxId();
    std::cout<< " max \n";
    id++;
    auto command = fmt::format(sql_commands::insertElementDocumentation, TableName, id, date);
    executeCommand(command);
    std::cout<< " command \n";
}

void DocumentationTable::updateElement(int id, const std::string &date)
{
    auto command = fmt::format(sql_commands::updateElementDocumentation, TableName, date, id);
    executeCommand(command);
}

std::map<std::string, std::string> DocumentationTable::getElementById(int id)
{
    return AbstractTable::getElements("TEXT_ID", "=", std::to_string(id))[0];
}

std::map<std::string, std::string> DocumentationTable::getElementById(std::string id)
{
    return AbstractTable::getElements("TEXT_ID", "=", id)[0];
}

vectorOfElementsAsMap DocumentationTable::getAllElementsWithText()
{
    return AbstractTable::getElements("TEXT_DATA", "!=", " " );
}

vectorOfElementsAsMap DocumentationTable::getAllDeletedElements()
{
    return AbstractTable::getElements("TEXT_DATA", "=", " ");
}

int DocumentationTable::getTableSize()
{
    return AbstractTable::getTableSize();
}

int DocumentationTable::getMinId()
{
    return AbstractTable::getMinAttribute("TEXT_ID");
}

int DocumentationTable::getMaxId()
{
    return AbstractTable::getMaxAttribute("TEXT_ID");
}

void DocumentationTable::removeElement(int id)
{
    std::cout<< "remove \n";
    auto command = fmt::format(sql_commands::updateElementDocumentation, TableName, " ", id);
    executeCommand(command);
}

void DocumentationTable::clearTable()
{
    AbstractTable::clearTable();
}

pqxx::result DocumentationTable::executeCommand(const std::string &command)
{
    return AbstractTable::executeCommand(command);
}

void DocumentationTable::setTableRowElement(const std::string &element)
{
    AbstractTable::setTableRowElement(element);
}
void DocumentationTable::setTableRowElement(const std::set<std::string> &elements)
{
    AbstractTable::setTableRowElement(elements);
}

DocumentationTable::~DocumentationTable() {}
