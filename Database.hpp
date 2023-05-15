#pragma once
#ifndef __Database__
#define __Database__

#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "SqlCommands.hpp"
#include "AbstractTable.hpp"

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
    static AbstractTable& getMtvTable();
    static AbstractTable& getDocumentationTable();
    virtual ~Database();
private:
    // Delete copy and move operator also copy and move constructor to be able to implement singelton
    Database(Database &) = delete;
    Database(Database &&) = delete;
    Database &operator=(Database const &) = delete;
    Database &operator=(Database const &&) = delete;
};

#endif