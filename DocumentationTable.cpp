#include "DocumentationTable.hpp"

DocumentationTable::DocumentationTable() : AbstractTable("Documentation");
connection(startConnection.c_str())
{
    pqxx::work work(connection);
    auto command = fmt::format(SqlCommands::createTableMtv, tableName);
    work.exec(command.c_str());
    work.commit();
}

void DocumentationTable::insertElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(SqlCommands::insertElementDocumentation, tableName, id, name, date);
    performExecuteCommand(command);
}

void DocumentationTable::updateElement(int id, const std::string &name, const std::string &date)
{
    auto command = fmt::format(SqlCommands::updateElementDocumentation, tableName, id, name, date);
    performExecuteCommand(command);
}

std::string DocumentationTable::getElement(int id)
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

DocumentationTable::~MtvTable()
{
}

DocumentationTable::~DocumentationTable()
{
}
