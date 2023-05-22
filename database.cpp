#include <fmt/core.h>
#include "database.hpp"
#include "sqlCommands.hpp"

std::map<Database::Tables, std::string> Database::connections;


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
    connections[connection] = fmt::format(sql_commands::startConnection, userName, Password).c_str();
   

    
}

Database::~Database() {}

