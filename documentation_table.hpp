
/*!
*************************************************************************
* @file documentation_table.hpp
*
* Klasse für Dokumentation.
*************************************************************************
* \copyright &copy; 2023 PINTSCH GmbH
*************************************************************************
*/

#ifndef DOCUMENTATION_TABLE
#define DOCUMENTATION_TABLE
#pragma once

#include <string>

#include "abstract_table.hpp"

/**
 * @brief Die Klasse "DocumentationTable" erbt von "AbstractTable" und implementiert alle abstrakten Methoden, die in "AbstractTable" deklariert sind.
Die Klasse ist eine befreundete Klasse von "Database", um dem Zugriff auf die Protected Konstruktoren zu ermöglichen.
Die Klasse kann nur über die Klasse "Database" instanziiert werden, da der Konstruktor protected ist, um sicherzustellen, dass nur eine Verbindung zur "DocumentationTable" vorhanden ist.
 */
class DocumentationTable : public AbstractTable
{
    /// @brief Definiert die Klasse Database als Friend-Klasse, damit Database den geschützten Konstruktor aufrufen kann
    friend class Database;

public:
    /// @brief Destruktor
    virtual ~DocumentationTable();

    /// @brief Methode zum Hinzufügen eines Elements in die Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param name Name des Elements
    /// @param date Datum des Elements
    void insertElement(int id, const std::string &name, const std::string &date);

    /// @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param name Der neue Name des Elements
    /// @param date Der neue Datum des Elements
    void updateElement(int id, const std::string &name, const std::string &date);

    /// @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @return Eine std::map, die die gesamte Zeile mit den entsprechenden Schlüssel-Wert-Paaren
    std::map<std::string, std::string> virtual getElementbyId(std::string id);

    /// @brief Methode zum Löschen eines Elements in der Datenbank
    /// @param id Der Schlüssel des Elements, das gelöscht werden so
    void removeElement(int id) override;

    /// @brief Methode zum Löschen aller Elemente in der Datenbank
    void clearTable() override;

    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param element Der Name einer Tabellenzeile
    void virtual setTableRowElement(const std::string &element) override;

    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param elements: die Namen aller Tabellenzeilen
    void virtual setTableRowElement(const std::set<std::string> &elements) override;

protected:
    /// @brief Konstruktor zum Herstellen einer Verbindung zur Datenbank
    DocumentationTable(std::string connectionData);

    /// @brief Methode zum Ausführen eines Befehls auf der Datenbank
    /// @param command Der Befehl als SQL-Befehl
    void executeCommand(const std::string &command);
};

#endif