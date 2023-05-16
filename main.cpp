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
  int key{228};
  auto& refMtv = Database::getMtvTable();
  auto& refDocu = Database::getDocumentationTable();

  refMtv.insertElement(key,"12");
  refDocu.insertElement(key, "1","21");
    
  std::cout << "element after insert mtv = " << refMtv.getElement(key)["NAME"].c_str() << " \n";
  std::cout << "element after insert Documentation = "<< refDocu.getElement(key)["NAME"].c_str() << "  " << refDocu.getElement(key)["DATE"].c_str() << " \n";
  
  refMtv.updateElement(key, "update mtv1");
  std::cout << "element after update mtv = " << refMtv.getElement(key)["NAME"] << " \n";
  refDocu.updateElement(key, "update document 1", "update document 1");
  std::cout << "element after update document = " << refDocu.getElement(key)["NAME"].c_str() << refDocu.getElement(key)["DATE"].c_str() << " \n";

  Database::getMtvTable().removeElement(key);
  Database::getDocumentationTable().removeElement(key);
  refMtv.deleteTable();
  refDocu.deleteTable();
  std::cout << "end";
}