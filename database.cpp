#include <fmt/core.h>
#include "database.hpp"

MtvTable &Database::getMtvTable()
{
    static MtvTable mtvTable(connections[Tables::mtv]);
    return mtvTable;
}

DocumentationTable &Database::getDocumentationTable()
{
    static DocumentationTable documentaionTable(connections[Tables::documentation]);
    return documentaionTable;
}

void Database::setConnectionData(Tables connection, std::string userName, std::string Password)
{
    connections[connection] = fmt::format(sql_commands::startConnection, userName, Password);
}

Database::~Database() {}