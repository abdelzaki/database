
#include <fmt/core.h>
#include <pqxx/pqxx>
#include "sqlCommands.hpp"
#include "documentationTable.hpp"

DocumentationTable::DocumentationTable(std::string connectionData) : AbstractTable("Documentation", connectionData)
{
    pqxx::work work(connection);
    auto command = fmt::format(sql_commands::createTableDocumentation, tableName);
    work.exec(command.c_str());
    work.commit();
}

void DocumentationTable::insertElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(sql_commands::insertElementDocumentation, tableName, id, name, date);

    executeCommand(command);
}

void DocumentationTable::updateElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(sql_commands::updateElementDocumentation, tableName, name, date, id);
    executeCommand(command);
}

std::map<std::string, std::string> DocumentationTable::getElement(int id)
{
    return AbstractTable::getElement(id);
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

void DocumentationTable::setConnectionData(std::string userName, std::string Password)
{

    connectionData = fmt::format(sql_commands::startConnection, userName, Password);
}
