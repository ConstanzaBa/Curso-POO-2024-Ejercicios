#include <iostream>
#include <string>
using namespace std;

template <class T>
void imprimir(T v[], int cantidad, bool ascendente = true) {
    // Algoritmo de ordenamiento por inserción
    for (int i = 1; i < cantidad; i++) {
        T key = v[i];
        int j = i - 1;

        // Ordenar ascendente o descendente según el valor
        if (ascendente) {
            // Ordenar de menor a mayor
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        } else {
            // Ordenar de mayor a menor
            while (j >= 0 && v[j] < key) {
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = key;
    }

    for (int i = 0; i < cantidad; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(int, char **) {
    int v1[5] = {5, 2, 4, 1, 6};
    float v2[4] = {2.3f, 5.1f, 0.0f, 2.0f};

    // Ordenar y imprimir el array de enteros de mayor a menor
    imprimir(v1, 5, false);

    // Ordenar y imprimir el array de flotantes de menor a mayor
    imprimir(v2, 4, true);

    return 0;
}
