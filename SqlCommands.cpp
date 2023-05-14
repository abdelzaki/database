#include "SqlCommands.hpp"
#include <string>



std::string SqlCommands::startConnection  = "host=localhost port=5432 dbname=test user=tuser password=linuxc";


std::string SqlCommands::createTable  = R"( CREATE TABLE IF NOT EXISTS MTV (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string SqlCommands::insertElement  = R"(INSERT INTO MTV (ID,NAME) VALUES ({}, '{}');)";

std::string SqlCommands::updateElement  = R"(UPDATE MTV  set NAME = '{}'  WHERE ID={};)";

std::string SqlCommands::findElement  = R"(SELECT NAME from MTV WHERE ID={};)";

std::string SqlCommands::removeElement = R"(DELETE FROM MTV WHERE ID={};)";

std::string SqlCommands::deleteTable = R"(DROP TABLE {};)";