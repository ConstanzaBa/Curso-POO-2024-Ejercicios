#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "trabajo.h"
using namespace std;

int main(int argc, char *argv[])
{
    Calculadora* UNO = new Calculadora();
    Calculadora* DOS = new Calculadora('+', '1', '2');
    Calculadora* TRES = new Calculadora('-', '3', '4');
    Calculadora* CUATRO = new Calculadora('*', '5', '6');
    Calculadora* CINCO = new Calculadora('/', '7', '8');
    vector <Calculadora*>* calc = new vector <Calculadora*>;
    calc->push_back(UNO);
    calc->push_back(DOS);
    calc->push_back(TRES);
    calc->push_back(CUATRO);
    calc->push_back(CINCO);

    sort(calc->begin(), calc->end());
}
