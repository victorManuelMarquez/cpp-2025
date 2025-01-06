#include <iostream>

using namespace std;

const int filas = 2;
const int columnas = 4;

void buscar(int valor, int matriz[][columnas]);

int main() {
    int matriz[filas][columnas] = {
        {0, 2, 9, 5},
        {9, 7, 8, 1}
    };
    int valor;
    string cadena;
    do {
        cout << "Ingrese un número para buscar en la matriz: ";
        getline(cin, cadena);
        valor = stoi(cadena);
    } while (!valor);
    buscar(valor, matriz);
    cout << "\nFin del programa." << endl;
    return 0;
}

void buscar(int valor, int matriz[][columnas]) {
    bool encontrado = false;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            if (valor == matriz[f][c])
                encontrado = true;
            cout << matriz[f][c] << " | ";
        }
        cout << '\n';
    }
    if (encontrado)
        cout << valor << " está en la matriz.\n";
    else
        cout << valor << " no está en la matriz.\n";
}