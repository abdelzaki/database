#include "database.hpp"

MtvTable &Database::getMtvTable()
{
    static MtvTable mtvTable;
    return mtvTable;
}

DocumentationTable &Database::getDocumentationTable()
{
    static DocumentationTable documentaionTable;
    return documentaionTable;
}

Database::~Database() {}