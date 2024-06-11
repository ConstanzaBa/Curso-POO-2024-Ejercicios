#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"
#include <QDebug>
#include <QString>

class Guitarra : public Instrumento {
public:
    Guitarra(QString &Marca, double Precio, int Cuerdas);
    void Set_Cant_Cuerdas(int Cuerdas);
    void Afinar() override;
    int Get_Cant_Cuerdas();

private:
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
