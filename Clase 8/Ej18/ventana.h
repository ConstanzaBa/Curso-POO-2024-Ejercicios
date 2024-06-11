#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QKeyEvent>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();
    QNetworkAccessManager * manager;
    void keyPressEvent(QKeyEvent *event);

private slots:
    void Reply(QNetworkReply *reply);

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
