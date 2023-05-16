#ifndef database
#define database
#pragma once

#include "mtvTable.hpp"
#include "documentationTable.hpp"
/**
 *  @brief Diese Klasse ist ein Singleton und besitzt keine Kopier- oder Move-Konstruktoren.
 *  Um diese Klasse zu verwenden, muss die Methode "getInstance" aufgerufen werden.
 * Zum Beispiel: Database::getInstance().insertElement();
 */
class Database
{

public:
    /* @brief
     * Diese Methode konstruiert ein Objekt,
     * das mit einer bestimmten Tabelle verknüpft ist und gibt dieses Objekt zurück.
     * @return Ein Objekt, das mit der angegebenen Tabelle verknüpft ist.
     */
    static MtvTable &getMtvTable();
    static DocumentationTable &getDocumentationTable();
    virtual ~Database();

private:
    // Singelton Design pattern
    Database(Database &) = delete;
    Database(Database &&) = delete;
    Database &operator=(Database const &) = delete;
    Database &operator=(Database const &&) = delete;
};

#endif