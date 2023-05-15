#include "Database.hpp"
#include <fmt/core.h>

AbstractTable& Database::getMtvTable()
{
    static AbstractTable mtvTable;
    return instance_1;
}
AbstractTable &Database::getDocumentationTable()
{

    static AbstractTable documentaionTable;

    return documentaionTable;
}


Database::~Database()
{
}