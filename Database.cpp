#include "Database.hpp"
#include <fmt/core.h>

AbstractTable &Database::getMtvTable()
{
    static MtvTable mtvTable;
    return mtvTable;
}

/*
AbstractTable &Database::getDocumentationTable()
{

    static AbstractTable documentaionTable;

    return documentaionTable;
}
*/

Database::~Database()
{
}