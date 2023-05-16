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

  Database::getMtvTable().insertElement(1,"12");
  Database::getDocumentationTable().insertElement(1,"1","2");
  

  std::cout << "element after insert mtv1 = " << Database::getMtvTable().getElement(key) << " \n";
  //Database::getInstanceMtv_2().insertElement(key, "insert mtv2");
  //std::cout << "element after insert mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  Database::getMtvTable().updateElement(key, "update mtv1");
  std::cout << "element after update mtv1 = " << Database::getMtvTable().getElement(key) << " \n";
  //Database::getInstanceMtv_2().updateElement(key, "update mtv2");
  //std::cout << "element after update mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  Database::getMtvTable().removeElement(key);
  std::cout << "element after remove mtv1 = " << Database::getMtvTable().getElement(key) << " \n";
  //Database::getInstanceMtv_2().removeElement(key);
  //std::cout << "element after remove mtv2 = " << Database::getInstanceMtv_2().getElement(key) << " \n";

  //Database::getMtvTable().deleteTable();
  //Database::getInstanceMtv_2().deleteTable("tabley");
}