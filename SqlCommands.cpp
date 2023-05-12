#include "SqlCommands.hpp"
#include <string>



std::string DatabaseCommands::startConnection  = "host=localhost port=5432 dbname=test user=tuser password=linuxc";


std::string DatabaseCommands::createTable  = R"( CREATE TABLE IF NOT EXISTS MTV (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);)";

std::string DatabaseCommands::insertElement  = R"(INSERT INTO MTV (ID,NAME) VALUES ({}, '{}');)";

std::string DatabaseCommands::updateElement  = R"(UPDATE MTV set NAME = '{}' where ID={};)";

std::string DatabaseCommands::findElement  = R"(SELECT NAME from MTV WHERE ID={};)";

std::string DatabaseCommands::removeElement = R"(DELETE FROM MTV WHERE ID={};)";

std::string DatabaseCommands::deleteTable = R"(DELETE FROM MTV WHERE ID={};)";