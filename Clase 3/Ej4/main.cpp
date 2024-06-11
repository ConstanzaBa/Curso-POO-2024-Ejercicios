#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> *entero = new vector<int>;
    for(int x = 0; x < 30; x++) {
        int temp = rand() % 15;
        entero->push_back(temp);
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Listado de 30 numeros enteros aleatorios entre 1 y 15:" << endl;
    for (int x = 0; x < 30; x++) {
        cout << entero->at(x) << ", ";
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
}
