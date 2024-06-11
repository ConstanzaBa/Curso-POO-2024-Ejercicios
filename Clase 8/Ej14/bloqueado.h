#ifndef Bloqueado_H
#define Bloqueado_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout> // Sistema de Grillas del QT
#include <QPushButton> // Para crear Botones
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

class Bloqueado : public QWidget {
    Q_OBJECT
private:
    QLabel* lBloqueado;
    QPushButton* pbSalir;
    QGridLayout* layout;

public:
    Bloqueado();

private slots:
    void finalizar_Programa();
};

#endif // Bloqueado_H
