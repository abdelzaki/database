#ifndef mtvTable
#define mtvtable

#pragma once
#include "abstractTable.hpp"

/// @brief Die Klasse für die MTVtabelle erbt von AbstractTable und implementiert alle abstrakten Methoden, die in AbstractTable definiert si
class MtvTable : public AbstractTable
{
    /// @brief Definiert die Klasse Database als Friend-Klasse, damit Database den geschützten Konstruktor aufrufen kann
    friend class Database;

public:
    /// @brief Methode zum Hinzufügen eines Elements in die Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param name Name des Elements
    void insertElement(int id, const std::string &value);

    /// @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @param name Der neue Name des Elements
    void updateElement(int id, const std::string &value);

    /// @brief Methode zum Lesen der Werte einer Zeile (Row) in der Datenbank
    /// @param id Der Schlüssel des Elements
    /// @return Eine std::map, die die gesamte Zeile mit den entsprechenden Schlüssel-Wert-Paaren
    std::map<std::string, std::string> virtual getElement(int id) override;

    /// @brief Methode zum Löschen eines Elements in der Datenbank
    /// @param id Der Schlüssel des Elements, das gelöscht werden so
    void removeElement(int id) override;

    /// @brief Methode zum Löschen aller Elemente in der Datenbank
    void clearTable();

    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param element Der Name einer Tabellenzeile
    void virtual setTableRowElement(const std::string &element) override;

    /// @brief Methode zum Übergeben der Tabellenzeilen, die in der Datenbank gelesen werden sollen
    /// @param elements: die Namen aller Tabellenzeilen
    void virtual setTableRowElement(const std::set<std::string> &elements) override;

    /// @brief Destruktor
    virtual ~MtvTable();

protected:
    /// @brief Methode zum Ausführen eines Befehls auf der Datenbank
    /// @param command Der Befehl als SQL-Befehl
    void performExecuteCommand(const std::string &command);

    /// @brief Konstruktor zum Herstellen einer Verbindung zur Datenbank
    MtvTable();
};

#endif