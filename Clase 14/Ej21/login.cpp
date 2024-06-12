#include "login.h"
#include "ui_login.h"
#include "ventana.h"


Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "../Ej21/db.sqlite" );
    ventana = new Ventana;

     connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

}

Login::~Login()
{
    delete ui;
    db.close();
}

bool Login::conectar(QString archivoSqlite)
{
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase Login::getDB()
{
    return db;
}

bool Login::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if ( db.open() )  {
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                   usuario + "' AND clave = '" + clave + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}

