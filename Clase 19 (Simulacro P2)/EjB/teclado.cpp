#include "teclado.h"

#include <QDebug>

Teclado::Teclado(QString &Marca, double Precio, int Teclas) {
    this->marca = Marca;
    this->precio = Precio;
    cantidad_de_teclas = Teclas;
}

void Teclado::Afinar() {
    qDebug() << "Afinando teclado...";
}

void Teclado::Set_Cantidad_Teclas(int Teclas) {
    cantidad_de_teclas = Teclas;
}

int Teclado::Get_Cant_Cuerdas() {
    return cantidad_de_teclas;
}
