#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB *AdminDB::Instancia = nullptr;

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB *AdminDB::getInstancia() {
    if (Instancia == nullptr) {
        Instancia = new AdminDB;
    }
    return Instancia;
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::leerLinea(int id, int &x_inicial, int &y_inicial, int &x_final, int &y_final )
{
    if (db.open()) {
           QSqlQuery query;
           query.prepare("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas WHERE id = :id");
           query.bindValue(":id", id);

           if (query.exec() && query.next()) {
               x_inicial = query.value(0).toInt();
               y_inicial = query.value(1).toInt();
               x_final = query.value(2).toInt();
               y_final = query.value(3).toInt();
               return true;
           }
       }

       return false;
}
