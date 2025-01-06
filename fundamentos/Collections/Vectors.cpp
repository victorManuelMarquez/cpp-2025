#include <iostream>
#include <vector>

using namespace std;

void mostrarVector(const vector<int> &vector);

void insertarNumAlFinal(vector<int> &vector);

void insertarNumEnX(vector<int> &vector);

int main() {
    vector<int> vectorEmpty; // vacío
    vector<int> vectorDeclarado(8); // de 8 elementos con valores por defecto "0" en este caso
    mostrarVector(vectorDeclarado);
    vector<int> vectorIniciado = {24, -2, 0, 1}; // inicio con valores
    mostrarVector(vectorIniciado);
    vector<int> vectorInicializado(6, 1); // de 6 elementos e inicializados en "1"
    mostrarVector(vectorInicializado);

    insertarNumAlFinal(vectorInicializado);
    mostrarVector(vectorInicializado);

    insertarNumEnX(vectorDeclarado);
    mostrarVector(vectorDeclarado);
    
    cout << "Fin del programa...\n";
    return 0;
}

void mostrarVector(const vector<int> &vector) {
    cout << "Vector de " << vector.size() << " elementos: ";
    for (int i = 0; i < vector.size(); i++) {
        cout << vector.at(i) << ", ";
    }
    cout << "fin del vector.\n";
}

void insertarNumAlFinal(vector<int> &vector) {
    int nuevo;
    string cadena;
    do {
        cout << "Ingrese un número para insertar al final del vector: ";
        getline(cin, cadena);
        nuevo = stoi(cadena);
    } while (!nuevo);
    vector.push_back(nuevo);
}

void insertarNumEnX(vector<int> &vector) {
    int pos;
    string cadena;
    do {
        cout << "Ingrese la posición en la que desea insertar un dato: ";
        getline(cin, cadena);
        pos = stoi(cadena);
    } while (pos < 0);
    int num;
    do {
        cout << "Ingrese el número a insertar en " << pos << ": ";
        getline(cin, cadena);
        num = stoi(cadena);
    } while (!num);
    vector.insert(vector.begin() + pos, num);
}