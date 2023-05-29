#include <string>
#include "sql_commands.hpp"

std::string sql_commands::startConnection = "host=localhost port=5432 dbname=test user={} password={}";

std::string sql_commands::createTableMtv = R"(CREATE TABLE IF NOT EXISTS {} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string sql_commands::insertElementMtv = R"(INSERT INTO {} (ID,NAME) VALUES ({}, '{}');)";

std::string sql_commands::updateElementMtv = R"(UPDATE {}  set NAME = '{}'  WHERE ID={};)";

std::string sql_commands::getElement = R"(SELECT * from {} WHERE {} {} '{}';)";

std::string sql_commands::getAllElements = R"(SELECT * from {};)";

std::string sql_commands::removeElement = R"(DELETE FROM {} WHERE ID={};)";

std::string sql_commands::clearTable = R"(DELETE FROM {};)";

std::string sql_commands::createTableDocumentation = R"(CREATE TABLE IF NOT EXISTS {} (
                                                        ID SERIAL PRIMARY KEY NOT NULL,
                                                        TEXT_ID INT NOT NULL UNIQUE, 
                                                        TEXT_DATA TEXT NOT NULL);)";

std::string sql_commands::insertElementDocumentation = R"(INSERT INTO {} (TEXT_ID,TEXT_DATA) VALUES ({}, {});)";

std::string sql_commands::updateElementDocumentation = R"(UPDATE {}  set TEXT_DATA = '{}' WHERE TEXT_ID={};)";

std::string sql_commands::minAttribute = R"(SELECT MIN({}) AS minAttribute from {})";

std::string sql_commands::maxAttribute = R"(SELECT MAX({}) AS maxattribute from {};)";
