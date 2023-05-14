/* std libraries */
#include <iostream>
#include <string>
/* Third Party libraries */
#include <pqxx/pqxx>
#include <fmt/core.h>
/* project header */
#include "Database.hpp"

int main()
{
  int key{100};
  Database::getInstance().insertElement(key, "insert");
  std::cout << "element after insert = " << Database::getInstance().getElement(key) << " \n";
  Database::getInstance().updateElement(key, "update");
  std::cout << "element after update = " << Database::getInstance().getElement(key) << " \n";
  Database::getInstance().removeElement(key);
  std::cout << "element after remove = " << Database::getInstance().getElement(key) << "  \n";
  Database::getInstance().deleteTable("MTV");
}