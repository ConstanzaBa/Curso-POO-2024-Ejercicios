#include "viento.h"

Viento::Viento(QString &Marca, double Precio, QString Metal) {
   this->marca = Marca;
   this->precio = Precio;
   metal_usado = Metal;
}

void Viento::Afinar() {
    qDebug() <<"Afinando viento...";
}

void Viento::Set_Metal_Usado(QString Metal) {
    metal_usado = Metal;
}

QString Viento::Get_Metal_Usado() {
    return metal_usado;
}

