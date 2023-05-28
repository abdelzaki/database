/*!
*************************************************************************
* @file abstract_table.hpp
*
* Abstrakte Klasse für Datenbankbefehle.
*************************************************************************
* \copyright &copy; 2023 PINTSCH GmbH
*************************************************************************
*/

#ifndef ABSTRACT_TABLE
#define ABSTRACT_TABLE
#pragma once

#include <string>
#include <set>
#include <map>
#include <vector>

#include <pqxx/pqxx>

/** @brief Die abstrakte Klasse "AbstractTable" ermöglicht die Kommunikation mit einer Datenbank.
Die klasse bietet eine standardmäßige Implementierung einiger Methoden, die von Unterklassen überschrieben werden können.
Die Klasse verwendet die Bibliohtek "pqxx" um Verbindung zu PostgreSQL zu erstellen
Die Klasse verwendet die Bibliohtek  "fmt" um String zu formatieren.
Der Member "connection" (Verbindungsinformationen) sollte in der Konstruktor der Klasse mit den entsprechenden Parametern initialisiert werden.
die Subklasse sollte den Tabellenname und die Verbindungsinformationen(Host, Port, Database Nname, Username, Passwort) an die Klasse übergeben.
Beispiel für die Verwendung der Klasse abstractTable
 \code
 std::string tableName = "mtv"
 std::string connectionData = "host=localhost port=3424 dbname= user=Serves1 password=ServesPintsch"
 DocumentationTable::DocumentationTable(connectionData) : AbstractTable(tableName, connectionData)
 \endcode
 */
class AbstractTable
{

   typedef std::map<std::string, std::string> elementAsMap;
   typedef std::vector<elementAsMap> vectorOfElementsAsMap;

protected:
   //! @brief Name der Tabelle
   std::string TableName;

   //! @brief Verbindung zur Datenbank mit datenbank informationen (host, port, dbname, user, password)
   pqxx::connection Connection;

   //! @brief Namen der Tabellezeilen
   std::set<std::string> TableRowElements;

public:
   /**
    * @brief Konstruktor zum Herstellen einer Verbindung zur Datenbank
    *
    * @param table Der Name der Tabelle
    * @param connection Verbindungsdaten zur Datenbank
    */
   AbstractTable(const std::string &table, std::string &connection);

   /**
    * @brief Destruktor
    *
    */
   virtual ~AbstractTable();

   /**
    * @brief Methode zum Hinzufügen eines Elements in die Datenbank
    *
    * @param id Der Schlüssel des Elements
    * @param value Der Wert, der in die Datenbank eingefügt werden soll
    */
   void virtual insertElement(int id, const std::string &value);

   /**
    * @brief Methode zum Aktualisieren der Werte eines vorhandenen Elements in der Datenbank
    *
    * @param id Der Schlüssel des Elements
    * @param value Der neue Wert, der für das Element verwendet werden soll
    */
   void virtual updateElement(int id, const std::string &value);

   /**
    * @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    *
    * @param id Der Schlüssel des Elements
    * @retval Eine std::map, die die gesamte Zeile mit den entsprechenden Schlüssel-Wert-Paaren
    */
   vectorOfElementsAsMap virtual getElement(std::string attribute, std::string compare, std::string value);

   int virtual getMinAttribute(std::string attribute);

   int virtual getMaxAttribute(std::string attribute);

   /**
    * @brief Methode zum Löschen eines Elements in der Datenbank
    *
    * @param id Der Schlüssel des Elements
    */
   void virtual removeElement(int id) = 0;

   /**
    * @brief Methode zum Löschen aller Elemente in der Datenbank
    */
   void virtual clearTable() = 0;

   /**
    * @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    *
    * @param element Der Name einer Tabellenzeile
    */
   void virtual setTableRowElement(const std::string &element) = 0;

   /**
    * @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    *
    * @param elements die Namen aller Tabellenzeilen
    */
   void virtual setTableRowElement(const std::set<std::string> &elements) = 0;

protected:
   /**
    * @brief Methode zum Ausführen eines Befehls auf der Datenbank
    *
    * @param command Der Befehl als SQL-Befehl
    */
   void virtual executeCommand(const std::string &command) = 0;

   vectorOfElementsAsMap virtual executeGetCommand(const std::string &command);
};

#endif