#include <string>
#include "sqlCommands.hpp"

std::string sql_commands::startConnectionMtv = "host=localhost port=5432 dbname=test user=tuser password=linuxc";

std::string sql_commands::startConnectionDocumentation = "host=localhost port=5432 dbname=test user=tuser password=linuxc";

std::string sql_commands::createTableMtv = R"(CREATE TABLE IF NOT EXISTS {} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string sql_commands::insertElementBasic = R"(INSERT INTO {} (ID,NAME) VALUES ({}, '{}');)";

std::string sql_commands::updateElementBasic = R"(UPDATE {}  set NAME = '{}'  WHERE ID={};)";

std::string sql_commands::findElementBasic = R"(SELECT * from {} WHERE ID={};)";

std::string sql_commands::removeElementBasic = R"(DELETE FROM {} WHERE ID={};)";

std::string sql_commands::deleteTableBasic = R"(DROP TABLE {};)";

std::string sql_commands::createTableDocumentation = R"(CREATE TABLE IF NOT EXISTS {} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, DATE TEXT NOT NULL);)";

std::string sql_commands::insertElementDocumentation = R"(INSERT INTO {} (ID,NAME,DATE) VALUES ({}, '{}', '{}');)";

std::string sql_commands::updateElementDocumentation = R"(UPDATE {}  set NAME = '{}', DATE = '{}' WHERE ID={};)";
