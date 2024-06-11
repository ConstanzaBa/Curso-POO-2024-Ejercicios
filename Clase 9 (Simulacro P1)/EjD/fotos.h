// Fotos.h

#ifndef Fotos_H
#define Fotos_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include <ventana.h>

class Fotos : public QWidget {
    Q_OBJECT
private:
    QLabel* lBienvenida, *lDescripcion;
    QPushButton* pbIngresar;
    QGridLayout* layout;
    Ventana* ventana;

public:
    Fotos();

private slots:
    void slot_Iniciar();
};

#endif // Fotos_H
