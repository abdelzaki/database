#include "MtvTable.hpp"

MtvTable::MtvTable() : AbstractTable("MTV", SqlCommands::startConnection)
{

}

void MtvTable::insertElement(int id, const std::string &value)
{
    AbstractTable::insertElement(id, value);
}

void MtvTable::updateElement(int id, const std::string &value){
    AbstractTable::updateElement(id, value);
    }

std::string MtvTable::getElement(int id)
{
    return AbstractTable::getElement(id);
}

void MtvTable::removeElement(int id)
{
    AbstractTable::removeElement(id);
}

void MtvTable::deleteTable(const std::string &table)
{
    AbstractTable::deleteTable(table);
}

void MtvTable::performExecuteCommand(const std::string &command)
{
    std::cout << command;
}

MtvTable::~MtvTable()
{
}