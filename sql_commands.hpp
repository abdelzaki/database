#ifndef SQL_COMMANDS
#define SQL_COMMANDS
#pragma once

#include <string>

/// @brief Namespace für SQL-Befehle
namespace sql_commands
{

  /// @brief Befehl zur Erstellung einer Verbindung zur MTV-Tabelle in der Datenbank
  extern std::string startConnection;

  /// @brief Befehl zur Erstellung einer Verbindung zur Doku-Tabelle in der Datenbank
  extern std::string startConnectionDocumentation;

  /// @brief Befehl zur Löschen aller Elementen der MTV-Tabelle in der Datenbank
  extern std::string createTableMtv;

  /// @brief Befehl zum Hinzufügen eines Elements in die MTV-Tabelle in der Datenbank
  extern std::string insertElementMtv;

  /// @brief Befehl zum Aktualisieren  eines Elements in der MTV-Tabelle in der Datenbank
  extern std::string updateElementMtv;

  extern std::string createTableDocumentation;

  /// @brief Befehl zum Hinzufügen eines Elements in die Doku-Tabelle in der Datenbank
  extern std::string insertElementDocumentation;

  /// @brief Befehl zum Aktualisieren  eines Elements in der Doku-Tabelle in der Datenbank
  extern std::string updateElementDocumentation;

  /// @brief Befehl zum Finden  eines Elements in der Datenbank
  extern std::string findElement;

  /// @brief Befehl zum Löschen  eines Elements in der Datenbank
  extern std::string removeElement;

  /// @brief Befehl zum Löschen  aller Elemente in der Datenbank
  extern std::string clearTable;

  extern std::string maxAttribute;

  extern std::string minAttribute;

};
#endif