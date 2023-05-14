#include<iostream>
#include<pqxx/pqxx>
#include<string>
#include "Database.hpp"
#include <fmt/core.h>

int main(){
  int key = 3;
 std::cout << "Main 1\n";
  Database::getInstance().insertElement(key,"insert");
  std::cout << "Main 2\n";
  Database::getInstance().getElement(key);
  std::cout << "Main 3\n";
  Database::getInstance().updateElement(key,"update");
  std::cout << "Main 4\n";
  //Database::getInstance().removeElement(5);
  //Database::getInstance().deleteTable("5");


  std::cout << "Main \n";
}