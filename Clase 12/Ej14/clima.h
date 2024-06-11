#ifndef Clima_H
#define Clima_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QTs
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

class Clima : public QObject {
    Q_OBJECT
private:
    double latitud, longitud, temperatura;
    QNetworkAccessManager* manager;

public:
    Clima(double latitud, double longitud, QObject* parent = nullptr);

signals:
    void ClimaChanged(const QString &temperatura);

public slots:
    void obtenerTemperatura();

private slots:
    void slot_descargaFinalizada(QNetworkReply* reply);
};

#endif // Clima_H
