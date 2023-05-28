
#include <iostream>
#include <sstream>
#include <fmt/core.h>
#include <pqxx/pqxx>
#include "sql_commands.hpp"
#include "documentation_table.hpp"

DocumentationTable::DocumentationTable(std::string connectionData) : AbstractTable("Documentation_t", connectionData)
{
    pqxx::work work(Connection);
    auto command = fmt::format(sql_commands::createTableDocumentation, TableName);
    work.exec(command.c_str());
    work.commit();
}

void DocumentationTable::insertElement(const std::string &date)
{ std::cout << " before getMinId(); \n";
    int id = getMaxId();
    std::cout << " getMinId(); \n";
    id++;
    std::cout<< " iD  = " << id << " \n";
    auto command = fmt::format(sql_commands::insertElementDocumentation, TableName, id, date);
    std::cout << " sql_commands::insertElementDocumentation \n";
    executeCommand(command);
    std::cout << " command 1 \n";
    int x;

}

void DocumentationTable::updateElement(int id, const std::string &date)
{
    auto command = fmt::format(sql_commands::updateElementDocumentation, TableName, date, id);
    executeCommand(command);
}

std::map<std::string, std::string> DocumentationTable::getElementById(int id)
{
    return AbstractTable::getElement("TEXT_ID", "=", std::to_string(id))[0];
}

std::map<std::string, std::string> DocumentationTable::getElementById(std::string id)
{
    return AbstractTable::getElement("TEXT_ID", "=", id)[0];
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
    AbstractTable::removeElement(id);
}

void DocumentationTable::clearTable()
{
    AbstractTable::clearTable();
}

void DocumentationTable::executeCommand(const std::string &command)
{
    AbstractTable::executeCommand(command);
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
