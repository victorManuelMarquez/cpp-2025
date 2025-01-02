#include <iostream>

// Este programa solicita un número y lo muestra por pantalla.
int main() {
    int valor = 0;
    std::cout << "Ingrese un número entero: ";
    std::cin >> valor; // De momento no se tratará ningun error aquí
    std::cout << "Usted ha ingresado " << valor << "\nFin del Programa.\n";
    return 0;
}