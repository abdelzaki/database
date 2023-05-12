#include<iostream>
#include<pqxx/pqxx>
#include<string>
#include "Database.hpp"
#include <fmt/core.h>

int main(){
 
  Database::getInstance().insertElement(12,"insert");
  Database::getInstance().getElement(123);
  Database::getInstance().updateElement(5,"update");
  Database::getInstance().removeElement(5);
  Database::getInstance().deleteTable("5");


  std::cout << "Main \n";
}