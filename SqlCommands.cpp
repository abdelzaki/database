#include "SqlCommands.hpp"
#include <string>

std::string SqlCommands::startConnection = "host=localhost port=5432 dbname=test user=tuser password=linuxc";

std::string SqlCommands::createTableMtv = R"(CREATE TABLE IF NOT EXISTS {} 
                                            (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string SqlCommands::insertElementBasic = R"(INSERT INTO {} (ID,NAME) VALUES ({}, '{}');)";

std::string SqlCommands::updateElementBasic = R"(UPDATE {}  set NAME = '{}'  WHERE ID={};)";

std::string SqlCommands::findElementBasic = R"(SELECT NAME from {} WHERE ID={};)";

std::string SqlCommands::removeElementBasic = R"(DELETE FROM {} WHERE ID={};)";

std::string SqlCommands::deleteTableBasic = R"(DROP TABLE {};)";


std::string SqlCommands::createTableDocumentation = R"(CREATE TABLE IF NOT EXISTS {} 
                                                    (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL,
                                                    DATE TEXT NOT NULL);)";

std::string SqlCommands::insertElementDocumentation = R"(INSERT INTO {} (ID,NAME,DATE) VALUES ({}, '{}', '{}');)";

std::string SqlCommands::updateElementDocumentation = R"(UPDATE {}  set NAME = '{}' set DATE = '{}' WHERE ID={};)";


