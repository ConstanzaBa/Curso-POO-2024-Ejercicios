#ifndef LOGIN_H
#define LOGIN_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>


#include <formulario.h>
#include <clima.h>
#include <bloqueado.h>

class Login : public QWidget {
    Q_OBJECT
    private:
        QLabel* lBienvenido, *lTemperatura, *lUsuario, *lClave;
        QLineEdit* leTemperatura, *leUsuario, *leClave;
        QPushButton* pbEntrar, *pbEsconderTemperatura;
        QGridLayout* layout;

        QNetworkAccessManager* manager;
        QImage im;

        Bloqueado *bloq;
        int intentos = 0;

    public:
        Login();

    private slots:
        void slot_validarUsuario();
        void slot_descargaFinalizada(QNetworkReply* reply);
        void slot_esconderTemperatura();
        void slot_actualizarTemperatura(const QString &temperatura);
        void slot_bloqueado();

    protected:
        void paintEvent(QPaintEvent* ) override;
};

#endif // LOGIN_H
