#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

// función con paso por valor y devuelve un resultado
int sumar(int n1, int n2) {
    return n1 + n2; // inline
}

// función con paso por referencia y no devuelve nada
void pedirNumero(int &n) {
    string valor;
    do {
        cout << "\nIngrese un número: ";
        getline(cin, valor);
        n = atoi(valor.c_str());
    } while (n < 1 || n > 100);
}

// función con paso por referencia sin alteración y devuelve resultado
int restar(const int& n1, const int& n2) {
    int r = n1 - n2;
    return r;
}

// protofunción
float division(int, int);

// función con valor por defecto
unsigned int potencia(const int& n1, int exp = 2) {
    unsigned int pot = 1;
    for (int i = 1; i <= exp; i++)
        pot *= n1;
    return pot;
}

// función sin parámetros y devuelve un resultado
short pedirNro() {
    string valor;
    short n;
    do {
        cout << "\nIngrese un número positivo menor que 13: ";
        getline(cin, valor);
        n = atoi(valor.c_str());
    } while (n < 1 || n > 12);
    return n;
}

// función recursiva
unsigned int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

// función principal
int main() {
    int n1, n2 = 0;
    pedirNumero(n1);
    pedirNumero(n2);
    cout << '\n' << n1 << " + " << n2 << " = " << sumar(n1, n2);
    cout << '\n' << n1 << " - " << n2 << " = " << restar(n1, n2);
    auto producto = [](int x, int y) -> int { return x * y; }; // función lambda
    cout << '\n' << n1 << " * " << n2 << " = " << producto(n1, n2);
    cout << '\n' << n1 << " / " << n2 << " = " << setprecision(3) << division(n1, n2);
    cout << '\n' << n1 << " ^ 2 = " << potencia(n1);
    cout << '\n' << n1 << " ^ " << n2 << " = " << potencia(n1, n2);
    short n = pedirNro();
    cout << n << "! = " << factorial(n);
    cout << "\nFin del Programa.\n";
    return 0;
}

float division(int n1, int n2) {
    return (float) n1 / (float) n2; // casting
}