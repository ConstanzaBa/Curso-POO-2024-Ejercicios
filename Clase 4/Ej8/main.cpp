#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;

    Persona(const string &nombre) : nombre(nombre) {}
    string descripcion() const { return "Persona con nombre: " + nombre; }
};

class Poste {
public:
    float altura;
    float diametro;

    Poste(float altura, float diametro) : altura(altura), diametro(diametro) {}
    string descripcion() const { return "Poste con altura de: " + to_string(altura) + " metros y " + to_string(diametro) + " cm de diametro"; }
};

template <typename T>
void imprimir(const T& objeto) {
    cout << objeto.descripcion() << endl;
}

int main() {
    Persona p1("Lucrecia");
    Persona p2("Carlos");

    Poste poste1(8.0f, 15.0f);
    Poste poste2(5.5f, 10.0f);

    imprimir(p1);
    imprimir(p2);
    imprimir(poste1);
    imprimir(poste2);

    return 0;
}
