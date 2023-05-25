
#include <iostream>
#include <string>

#include <pqxx/pqxx>
#include <fmt/core.h>

#include "database.hpp"

int main()
{
  int key{228};
  Database::setConnectionData(Database::Tables::DOCUMENTATION ,"tuser", "linuxc");
  Database::setConnectionData(Database::Tables::MTV,"tuser", "linuxc");

  auto &refMtv = Database::getMtvTable();
  auto &refDocu = Database::getDocumentationTable();
  refMtv.setTableRowElement("NAME");
  refDocu.setTableRowElement("NAME");
  refDocu.setTableRowElement("DATE");

  refMtv.insertElement(key, "12");
  refDocu.insertElement(key, "1", "21");

  std::cout << "element after insert mtv = " << refMtv.getElement(key)["NAME"].c_str() << " \n";
  std::cout << "element after insert Documentation = " << refDocu.getElement(key)["NAME"].c_str() << "  " << refDocu.getElement(key)["DATE"].c_str() << " \n";

  refMtv.updateElement(key, "update mtv1");
  std::cout << "element after update mtv = " << refMtv.getElement(key)["NAME"] << " \n";
  refDocu.updateElement(key, "update document 1", "update document 1");
  std::cout << "element after update document = " << refDocu.getElement(key)["NAME"].c_str() << refDocu.getElement(key)["DATE"].c_str() << " \n";

  Database::getMtvTable().removeElement(key);
  Database::getDocumentationTable().removeElement(key);
  refMtv.clearTable();
  refDocu.clearTable();
  std::cout << "end";
}