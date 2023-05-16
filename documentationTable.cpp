
#include <fmt/core.h>
#include <pqxx/pqxx>
#include "sqlCommands.hpp"
#include "documentationTable.hpp"

DocumentationTable::DocumentationTable() : AbstractTable("Documentation", sql_commands::startConnectionDocumentation)
{
    pqxx::work work(connection);
    auto command = fmt::format(sql_commands::createTableDocumentation, tableName);
    work.exec(command.c_str());
    work.commit();
}

void DocumentationTable::insertElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(sql_commands::insertElementDocumentation, tableName, id, name, date);

    performExecuteCommand(command);
}

void DocumentationTable::updateElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(sql_commands::updateElementDocumentation, tableName, name, date, id);
    performExecuteCommand(command);
}

pqxx::row DocumentationTable::getElement(int id)
{
    return AbstractTable::getElement(id);
}

void DocumentationTable::removeElement(int id)
{
    AbstractTable::removeElement(id);
}

void DocumentationTable::deleteTable()
{
    AbstractTable::deleteTable();
}

void DocumentationTable::performExecuteCommand(const std::string &command)
{
    AbstractTable::performExecuteCommand(command);
}

DocumentationTable::~DocumentationTable() {}
