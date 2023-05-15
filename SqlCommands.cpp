#include "SqlCommands.hpp"
#include <string>

std::string SqlCommands::startConnection = "host=localhost port=5432 dbname=test user=tuser password=linuxc";

std::string SqlCommands::createTable = R"( CREATE TABLE IF NOT EXISTS {}} (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string SqlCommands::insertElement = R"(INSERT INTO '{}' (ID,NAME) VALUES ({}, '{}');)";

std::string SqlCommands::updateElement = R"(UPDATE '{}'  set NAME = '{}'  WHERE ID={};)";

std::string SqlCommands::findElement = R"(SELECT NAME from '{}' WHERE ID={};)";

std::string SqlCommands::removeElement = R"(DELETE FROM '{}' WHERE ID={};)";

std::string SqlCommands::deleteTable = R"(DROP TABLE {};)";