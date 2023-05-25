#include <string>
#include "sql_commands.hpp"

std::string sql_commands::startConnection = "host=localhost port=5432 dbname=test user={} password={}";

std::string sql_commands::createTableMtv = R"(CREATE TABLE IF NOT EXISTS {} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string sql_commands::insertElementMtv = R"(INSERT INTO {} (ID,NAME) VALUES ({}, '{}');)";

std::string sql_commands::updateElementMtv = R"(UPDATE {}  set NAME = '{}'  WHERE ID={};)";

std::string sql_commands::findElement = R"(SELECT * from {} WHERE ID={};)";

std::string sql_commands::removeElement = R"(DELETE FROM {} WHERE ID={};)";

std::string sql_commands::clearTable = R"(DELETE FROM {};)";

std::string sql_commands::createTableDocumentation = R"(CREATE TABLE IF NOT EXISTS {} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, DATE TEXT NOT NULL);)";

std::string sql_commands::insertElementDocumentation = R"(INSERT INTO {} (ID,NAME,DATE) VALUES ({}, '{}', '{}');)";


std::string sql_commands::updateElementDocumentation = R"(UPDATE {}  set NAME = '{}', DATE = '{}' WHERE ID={};)";