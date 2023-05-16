#include "Database.hpp"
#include <fmt/core.h>

AbstractTable &Database::getMtvTable()
{
    static MtvTable mtvTable;
    return mtvTable;
}

DocumentationTable &Database::getDocumentationTable()
{
    static DocumentationTable documentaionTable;
    return documentaionTable;
}

Database::~Database()
{
}