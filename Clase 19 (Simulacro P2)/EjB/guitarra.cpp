#include "guitarra.h"

Guitarra::Guitarra(QString &Marca, double Precio, int Cuerdas) {
     this->marca = Marca;
     this->precio = Precio;
     cantidad_de_cuerdas = Cuerdas;
}

void Guitarra::Set_Cant_Cuerdas(int Cuerdas) {
    cantidad_de_cuerdas = Cuerdas;
}

void Guitarra::Afinar() {
    qDebug() << "Afinando guitarra...";
}

int Guitarra::Get_Cant_Cuerdas() {
    return  cantidad_de_cuerdas;
}
