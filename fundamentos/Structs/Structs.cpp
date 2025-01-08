#include <iostream>
#include <string>

using namespace std;

struct PERSONA {
    string nombre;
    string apellido;
    int edad;
} individuo;

void pedirNombreCompleto(PERSONA* p);

void pedirEdad(PERSONA* p);

void mostrar(const PERSONA& p);

int main(void) {
    pedirNombreCompleto(&individuo);
    pedirEdad(&individuo);
    mostrar(individuo);
    cout << "Fin del programa." << endl;
    return EXIT_SUCCESS;
}

void pedirNombreCompleto(PERSONA* p) {
    do {
        cout << "Ingrese el nombre del individuo: ";
        getline(cin, p->nombre);
    } while (p->nombre.empty());
    do {
        cout << "Ingrese el apellido de " << p->nombre << ": ";
        getline(cin, p->apellido);
    } while (p->apellido.empty());
}

void pedirEdad(PERSONA* p) {
    string valor;
    do {
        try {
            cout << "Ingrese la edad de " << p->nombre << ": ";
            getline(cin, valor);
            p->edad = stoi(valor);
        } catch (...) {
            cout << "¿? Reintentando...\n";
            p->edad = -1;
        }
    } while (p->edad < 0);
}

void mostrar(const PERSONA& p) {
    cout << "Nombre completo: " << p.nombre << ", " << p.apellido << '\n';
    cout << "Edad: " << p.edad << '\n';
}