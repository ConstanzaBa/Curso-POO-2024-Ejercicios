#include <QCoreApplication>
#include <iostream>
#include "trabajo.h"
using namespace std;

void Separacion() {
    for(int x = 0; x < 50; x++) {
        cout << ", ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Calculadora* calc = new Calculadora();
    cout << "------------------" << endl;
    cout << "Calculadora Simple" << endl;
    cout << "------------------" << endl;

    int x = -1;
    char OP;
    while (x == -1) {
        cout << "Ingrese la Operacion que desea realizar" << endl;
        cout << "Las Operaciones Validas son: +, -, *, /" << endl;
        cin >> OP;
        x = calc->setOperador(OP);
        Separacion();
    }

    float OP1, OP2;
    cout << "Ingrese su Primer Operando" << endl;
    Separacion();
    cin >> OP1;
    calc->setOperandoUno(OP1);
    Separacion();
    cout << "Ingrese su Segundo Operando" << endl;
    Separacion();
    cin >> OP2;
    calc->setOperandoDos(OP2);
    Separacion();
    float RESULT = calc->Operar();
    cout << "Su Resultado es: " << RESULT << endl;
}
