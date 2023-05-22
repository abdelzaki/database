#ifndef abstractTable
#define abstractTable
#pragma once

#include <string>
#include <set>
#include <map>
#include <pqxx/pqxx>

/// @brief  Abstrakte Klasse, die eine Verbindung zur Datenbank ermöglicht
// und eine Standardimplementierung für die abstrakte Methode bereitstellt
class AbstractTable
{
public:
    /// @brief Methode zum Hinzufügen eines Elements in die Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param value Der Wert, der in die Datenbank eingefügt werden soll
    void virtual insertElement(int id, const std::string &value);
    /// @brief Methode zum Aktualisieren der Werte eines vorhandenen Elements in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param value Der neue Wert, der für das Element verwendet werden soll
    void virtual updateElement(int id, const std::string &value);
    /// @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @return Eine std::map, die die gesamte Zeile mit den entsprechenden Schlüssel-Wert-Paaren
    std::map<std::string, std::string> virtual getElement(int id) = 0;

    /// @brief Methode zum Löschen eines Elements in der Datenbank
    /// @param id Der Schlüssel des Elements, das gelöscht werden so
    void virtual removeElement(int id) = 0;
    /// @brief Methode zum Löschen aller Elemente in der Datenbank
    void virtual clearTable() = 0;

    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param element Der Name einer Tabellenzeile
    void virtual setTableRowElement(const std::string &element) = 0;
    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param elements: die Namen aller Tabellenzeilen
    void virtual setTableRowElement(const std::set<std::string> &elements) = 0;

    /// @brief konstruktore um die
    /// @param table
    // AbstractTable(const std::string &table);

    /// @brief Konstruktor zum Herstellen einer Verbindung zur Datenbank
    /// @param table Der Name der Tabelle
    /// @param connection: Verbindungsdaten zur Datenbank
    AbstractTable(const std::string &table, std::string &connection);
    /// @brief Destruktor
    virtual ~AbstractTable();

protected:
    /// @brief Name der Tabelle
    std::string tableName;
    /// @brief Verbindung zur Datenbank
    pqxx::connection connection;
    /// @brief Namen der Tabellezeilen
    std::set<std::string> tableRowElements;
    /// @brief Methode zum Ausführen eines Befehls auf der Datenbank
    /// @param command Der Befehl als SQL-Befehl
    void virtual performExecuteCommand(const std::string &command) = 0;
};

#endif