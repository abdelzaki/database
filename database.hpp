#ifndef database
#define database
#pragma once

#include <map>
#include "mtvTable.hpp"
#include "documentationTable.hpp"

/**
 *  @brief Diese Klasse ist ein Singleton und besitzt keine Kopier- oder Move-Konstruktoren.
 *  Um diese Klasse zu verwenden, muss die Methode "getInstance" aufgerufen werden.
 * Zum Beispiel: Database::getMtvTable().insertElement();
 */
class Database
{

public:
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

    /// @brief Destruktor
    virtual ~Database();

public:
    /// @brief Enumeration für die Namen der Tabellen
    enum class Tables
    {
        mtv,
        documentation
    };

private:
    /// @brief Map für die Verbindungsnamen der Tabellen, Schlüssel ist der Enum Tables
    static std::map<Tables, std::string> connections;

    // Singelton Design pattern
    Database(Database &) = delete;
    Database(Database &&) = delete;
    Database &operator=(Database const &) = delete;
    Database &operator=(Database const &&) = delete;
};

#endif