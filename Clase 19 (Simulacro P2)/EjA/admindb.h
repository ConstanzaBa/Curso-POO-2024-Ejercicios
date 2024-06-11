#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class AdminDB : public QObject  {
    Q_OBJECT

public:

    static AdminDB *getInstancia();
    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    bool leerLinea( int id, int &x_inicial, int &y_inicial, int &x_final, int &y_final );

private:

    static AdminDB *Instancia;
    AdminDB();
    QSqlDatabase db;

};

#endif // ADMINDB_H
