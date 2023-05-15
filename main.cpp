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
  int key{99};

  Database::getInstanceMtv_1().insertElement(key, "insert mtv1");
  std::cout << "element after insert mtv1 = " << Database::getInstanceMtv_1().getElement(key) << " \n";
  Database::getInstanceMtv_2().insertElement(key, "insert mtv2");
  std::cout << "element after insert mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  Database::getInstanceMtv_1().updateElement(key, "update mtv1");
  std::cout << "element after update mtv1 = " << Database::getInstanceMtv_1().getElement(key) << " \n";
  Database::getInstanceMtv_2().updateElement(key, "update mtv2");
  std::cout << "element after update mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  Database::getInstanceMtv_1().removeElement(key);
  std::cout << "element after remove mtv1 = " << Database::getInstanceMtv_1().getElement(key) << " \n";
  Database::getInstanceMtv_2().removeElement(key);
  std::cout << "element after remove mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  Database::getInstanceMtv_1().deleteTable("tablex");
  Database::getInstanceMtv_2().deleteTable("tabley");
}