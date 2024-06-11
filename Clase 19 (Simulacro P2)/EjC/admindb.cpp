#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QCryptographicHash>
#include <QSqlRecord>

AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB *AdminDB::getInstancia()
{
    instancia = instancia ? instancia : new AdminDB;
    return instancia;
}

bool AdminDB::conectar( QString baseSqlite )
{
    db.setDatabaseName( baseSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

QStringList AdminDB::validarUsuario(QString usuario, QString clave)
{
    QStringList datosUsuario;

    if ( ! db.open() )  {
        return datosUsuario;
    }

    QSqlQuery *query = new QSqlQuery( db );
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
                                                 QCryptographicHash::Md5 ).toHex();
    query->exec( "SELECT nombre, apellido FROM usuarios WHERE usuario = '" +
                                      usuario + "' AND clave = '" + claveMd5 + "'" );
    qDebug() << claveMd5;

    while( query->next() )  {
    QSqlRecord registro = query->record();

    datosUsuario << query->value(registro.indexOf( "nombre" ) ).toString();
    datosUsuario << query->value( registro.indexOf( "apellido" ) ).toString();
    }

    qDebug() << datosUsuario;
    return datosUsuario;
}

QVector<QStringList> AdminDB::select(QString comando)
{
    QVector<QStringList> resultados;
    if (!db.open()) {
        return resultados;
    }

    // Ejecuta la consulta SELECT
    QSqlQuery query(comando);
    if (!query.exec()) {
        db.close();
        return resultados;
    }

    // Procesa los resultados
    while (query.next()) {
         QStringList info;
         QSqlRecord registro = query.record();

         for (int i = 0; i < registro.count(); ++i) {
             info += query.value(i).toString();
         }

         resultados.append(info);
    }

    db.close();
    return resultados;
}
