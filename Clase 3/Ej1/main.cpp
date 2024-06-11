#include <QCoreApplication>
#include <iostream>
using namespace std;

int main() {
    int *entero = new int [10];

    cout << "-------------------------------------------------------" << endl;
    cout << "Listado de 10 numeros enteros aleatorios entre 2 y 20: " << endl;
    for (int x = 0; x < 10; x++) {
        *(entero + x) = rand() % 20 + 2;
        cout << *(entero + x) << ", ";
    }
    cout << endl;
    cout << "-------------------------------------------------------" << endl;
}
