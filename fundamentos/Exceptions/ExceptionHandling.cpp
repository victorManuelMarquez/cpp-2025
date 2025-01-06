#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

int pedirNumero();

void division(const int &n1, const int &n2);

int main() {
    int n1 = pedirNumero();
    int n2 = pedirNumero();
    try {
        division(n1, n2);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << "Fin del programa." << endl;
    return EXIT_SUCCESS;
}

int pedirNumero() {
    int valor;
    bool continuar;
    string cadena;
    do {
        try {
            cout << "Ingrese un número entero: ";
            getline(cin, cadena);
            valor = stoi(cadena); // stoi existe desde C++ 11
            continuar = false;
        } catch (const invalid_argument& exception) {
            cout << "Error (" << exception.what() << ") no ha ingresado un número válido.\n";
            continuar = true;
        } catch (...) {
            cout << "Excepción desconocida.\n";
        }
    } while (continuar);
    return valor;
}

void division(const int &n1, const int &n2) {
    cout << "División: ";
    cout << n1 << " / " << n2 << " = ";
    if (n2 == 0)
        throw runtime_error("Math Error!");
    cout << setprecision(3) << (float) n1 / (float) n2 << '\n';
}