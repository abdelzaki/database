
#include <fmt/core.h>
#include <pqxx/pqxx>
#include "sqlCommands.hpp"
#include "mtvTable.hpp"

MtvTable::MtvTable() : AbstractTable("MTV", sql_commands::startConnectionMtv)
{
    pqxx::work work(connection);
    auto command = fmt::format(sql_commands::createTableMtv, tableName);
    work.exec(command.c_str());
    work.commit();
}

void MtvTable::insertElement(int id, const std::string &value)
{
    AbstractTable::insertElement(id, value);
}

void MtvTable::updateElement(int id, const std::string &value)
{
    AbstractTable::updateElement(id, value);
}

pqxx::row MtvTable::getElement(int id)
{
    return AbstractTable::getElement(id);
}

void MtvTable::removeElement(int id)
{
    AbstractTable::removeElement(id);
}

void MtvTable::deleteTable()
{
    AbstractTable::deleteTable();
}

void MtvTable::performExecuteCommand(const std::string &command)
{
    AbstractTable::performExecuteCommand(command);
}

MtvTable::~MtvTable()
{
}
