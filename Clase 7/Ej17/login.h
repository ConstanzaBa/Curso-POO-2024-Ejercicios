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

#include <ventana.h>

class Login : public QWidget {
    Q_OBJECT
    private:
        QLabel* lBienvenido, *lUsuario, *lClave;
        QLineEdit* leUsuario, *leClave;
        QPushButton* pbEntrar;
        QGridLayout* layout;

        QNetworkAccessManager* manager;
        QImage im;

    public:
        Login();

    private slots:
        void slot_validarUsuario();
        void slot_descargaFinalizada(QNetworkReply* reply);

    protected:
        void paintEvent(QPaintEvent* ) override;
};

#endif // LOGIN_H
