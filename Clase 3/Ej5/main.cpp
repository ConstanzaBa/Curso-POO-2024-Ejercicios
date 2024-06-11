#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>* OrdenAlfabetico(vector<string>* linea) {
    sort(linea->begin(), linea->end());
    return linea;
}

int main(int argc, char *argv[])
{
    vector<string>* linea = new vector<string>;
    for(int x = 0; x < 5; x++) {
        string almacen;
        cout << "Ingrese palabra " << (x + 1) << ": ";
        cin >> almacen;
        linea->push_back(almacen);
    }

    cout << "-----------------------------------------" << endl;
    cout << "Palabras ingresadas: " << endl;
    for(int x = 0; x < 5; x++) {
        cout << linea->at(x) << endl;
    }
    cout << "-----------------------------------------" << endl;

    OrdenAlfabetico(linea);

    cout << "-----------------------------------------" << endl;
    cout << "Palabras ingresadas en orden alfabetico: " << endl;
    for(int x = 0; x < 5; x++) {
        cout << linea->at(x) << endl;
    }
    cout << "-----------------------------------------" << endl;
}
