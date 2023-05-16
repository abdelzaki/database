#pragma once
#ifndef __SqlCommands__
#define __SqlCommands__

#include <string>

namespace SqlCommands
{

  extern std::string startConnection;

  extern std::string startConnectionDocumentation;

  extern std::string createTableMtv; 
  
  extern std::string insertElementBasic;

  extern std::string updateElementBasic;

  extern std::string createTableDocumentation;

  extern std::string insertElementDocumentation;

  extern std::string updateElementDocumentation;


  extern std::string findElementBasic;

  extern std::string removeElementBasic;

  extern std::string deleteTableBasic;

};
#endif