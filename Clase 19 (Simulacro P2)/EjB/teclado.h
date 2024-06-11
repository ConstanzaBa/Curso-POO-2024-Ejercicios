#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"

#include <QDebug>
#include <QString>

class Teclado : public Instrumento {
public:
    Teclado(QString &Marca, double Precio, int Teclas);
    void Afinar() override;
    void Set_Cantidad_Teclas(int Teclas);
    int Get_Cant_Cuerdas();

private:
    int cantidad_de_teclas;
};

#endif // TECLADO_H
