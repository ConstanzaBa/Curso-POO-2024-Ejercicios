#include <QObject>
#include <QSqlDatabase>
#include <QString>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    explicit AdminDB(QObject *parent = nullptr);

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    bool validarUsuario( QString tabla, QString usuario, QString clave );

private:
    QSqlDatabase db;
};
