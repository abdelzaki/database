/*!
*************************************************************************
* @file database.hpp
*
* Klasse für eine database, der über das iUZ-Protokoll kommuniziert.
*************************************************************************
* \copyright &copy; 2023 PINTSCH GmbH
*************************************************************************
*/

#ifndef DATABASE
#define DATABASE
#pragma once

#include <map>
#include "mtv_table.hpp"
#include "documentation_table.hpp"

/**
 * @brief Die Klasse ist für die Herstellung einer Verbindung zur richtigen Datenbank mit Benutzername und Passwort verantwortlich.
Diese Klasse ist ein Singleton und besitzt keine Kopier- oder Move-Konstruktoren.
Alle Methoden sind statisch und können nur über den Klassennamen aufgerufen werden z.B Database::setConnectionData(....);
Um Operationen auf einer bestimmten Tabelle durchzuführen, muss zuerst eine Verbindungsdaten übergeben werden
Die entsprechende Tabelle sollte vor jeder Operation aufgerufen werden, z.B. Database::getMtvTable().insertElement(key, value).

Beispiel für die Verwendung der Klasse IuzTcpClient:
\code
Database::setConnectionData(Database::Tables::documentation,"Serves1", "ServesPintsch");
Database::getDocumentationTable().setTableRowElement("NAME");
Database::getDocumentationTable().insertElement(key, "12");
 \endcode
 */
class Database
{
public:
    /// @brief Enumeration für die Namen der Tabellen
    enum class Tables
    {
        MTV,
        DOCUMENTATION
    };

private:
    /// @brief Map für die Verbindungsnamen der Tabellen, Schlüssel ist der Enum Tables
    static std::map<Tables, std::string> connections;

    // Singelton Design pattern
    Database(Database &) = delete;
    Database(Database &&) = delete;
    Database &operator=(Database const &) = delete;
    Database &operator=(Database const &&) = delete;

public:
    /// @brief Destruktor
    virtual ~Database();

    /* @brief
     * Diese Methode konstruiert ein Objekt,
     * das mit der MTV Tabelle verknüpft ist und gibt dieses Objekt zurück.
     * @return Ein Objekt, das mit der angegebenen Tabelle verknüpft ist.
     */
    static MtvTable &getMtvTable();
    /* @brief
     * Diese Methode konstruiert ein Objekt,
     * das mit der Doku Tabelle verknüpft ist und gibt dieses Objekt zurück.
     * @return Ein Objekt, das mit der angegebenen Tabelle verknüpft ist.
     */
    static DocumentationTable &getDocumentationTable();

    /// @brief Methode zum Setzen des Benutzernamens und Passworts für die spätere Verbindung zur Datenbank
    /// @param connection Name der Table
    /// @param userName Benutzername
    /// @param Password  Passwort
    void static setConnectionData(Tables connection, std::string userName, std::string Password);
};

#endif