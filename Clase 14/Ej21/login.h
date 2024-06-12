#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

#include "ventana.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();
    bool validarUsuario( QString tabla, QString usuario, QString clave );

private:
    Ui::Login *ui;
    QSqlDatabase db;
    Ventana *ventana;
};
#endif // LOGIN_H
