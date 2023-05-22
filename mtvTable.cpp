
#include <fmt/core.h>
#include <pqxx/pqxx>
#include "sqlCommands.hpp"
#include "mtvTable.hpp"

MtvTable::MtvTable() : AbstractTable("MTV", connectionData)
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

std::map<std::string, std::string> MtvTable::getElement(int id)
{
    return AbstractTable::getElement(id);
}

void MtvTable::removeElement(int id)
{
    AbstractTable::removeElement(id);
}

void MtvTable::clearTable()
{
    AbstractTable::clearTable();
}

void MtvTable::performExecuteCommand(const std::string &command)
{
    AbstractTable::performExecuteCommand(command);
}

MtvTable::~MtvTable()
{
}

void MtvTable::setTableRowElement(const std::string &element)
{
    AbstractTable::setTableRowElement(element);
}
void MtvTable::setTableRowElement(const std::set<std::string> &elements)
{
    AbstractTable::setTableRowElement(elements);
}

void MtvTable::setConnectionData(std::string userName, std::string Password)
{
    connectionData = fmt::format(sql_commands::startConnection, userName, Password);
}