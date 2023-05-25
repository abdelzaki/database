#include <fmt/core.h>
#include "database.hpp"
#include "sql_commands.hpp"

std::map<Database::Tables, std::string> Database::Connections;

MtvTable &Database::getMtvTable()
{
    static MtvTable mtvTable(Connections[Tables::MTV]);

    return mtvTable;
}

DocumentationTable &Database::getDocumentationTable()
{
    static DocumentationTable documentaionTable(Connections[Tables::DOCUMENTATION]);

    return documentaionTable;
}

void Database::setConnectionData(Tables connection, std::string userName, std::string Password)
{
    Connections[connection] = fmt::format(sql_commands::startConnection, userName, Password).c_str();
}

Database::~Database() {}