
#include <iostream>
#include <string>

#include <pqxx/pqxx>
#include <fmt/core.h>

#include "database.hpp"

int main()
{
  int key = 2;
  Database::setConnectionData(Database::Tables::DOCUMENTATION ,"tuser", "linuxc");
  //Database::setConnectionData(Database::Tables::MTV,"tuser", "linuxc");

  //auto &refMtv = Database::getMtvTable();
  auto &refDocu = Database::getDocumentationTable();
  //refMtv.setTableRowElement("NAME");
  refDocu.setTableRowElement("TEXT_DATA");
  refDocu.setTableRowElement("TEXT_ID");
  /*
Database::getDocumentationTable().removeElement(1);
Database::getDocumentationTable().removeElement(3);
Database::getDocumentationTable().removeElement(2);
Database::getDocumentationTable().removeElement(5);
Database::getDocumentationTable().removeElement(6);
Database::getDocumentationTable().removeElement(7);
  */
  refDocu.insertElement("1");
  refDocu.insertElement("2");
  refDocu.insertElement("3");
  refDocu.insertElement("4");
  Database::getDocumentationTable().removeElement(2);


  std::cout << refDocu.getTableSize() << " \n";

  std::vector<std::map<std::string, std::string>> result = refDocu.getAllDeletedElements();
  for(auto it : result){
    for(auto itt : it){

      std::cout<< itt.first << " " << itt.second << " \n";
    }
  }

std::cout<< "------- \n";
    std::vector<std::map<std::string, std::string>> result1 = refDocu.getAllElementsWithText();
  for(auto it : result1){
    for(auto itt : it){

      std::cout<< itt.first << " " << itt.second << " \n";
    }
  }
  result1.insert(result1.end(), result.begin(),result.end() );

  std::cout<< " together------- \n";

  for(auto it : result1){
    for(auto itt : it){

      std::cout<< itt.first << " " << itt.second << " \n";
    }
  }

  
  //std::cout << "element after insert mtv = " << refMtv.getElement(key)["NAME"].c_str() << " \n";
  //std::cout << "element after insert Documentation = " << refDocu.getElementById(key)["TEXT_DATA"].c_str() << "  " << refDocu.getElementById(key)["DATE"].c_str() << " \n";

  //refMtv.updateElement(key, "update mtv1");
  //std::cout << "element after update mtv = " << refMtv.getElement(key)["NAME"] << " \n";
  //refDocu.updateElement(key, "update document 1");
  //std::cout << "element after update document = " << refDocu.getElementById(key)["TEXT_DATA"].c_str() << refDocu.getElementById(key)["DATE"].c_str() << " \n";

  //Database::getMtvTable().removeElement(key);
  //Database::getDocumentationTable().removeElement(key);
  //refMtv.clearTable();
  //refDocu.clearTable();
  std::cout << "end";
}