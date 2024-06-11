#ifndef VIENTO_H
#define VIENTO_H

#include "instrumento.h"

#include <QDebug>
#include <QString>

class Viento :public Instrumento {
public:
    Viento(QString &Marca, double Precio,QString Metal);
    void Afinar() override;
    void Set_Metal_Usado(QString Metal);
    QString Get_Metal_Usado();

private:
    QString metal_usado;
};

#endif // VIENTO_H
