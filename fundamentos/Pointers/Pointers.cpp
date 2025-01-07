#include <iostream>

using namespace std;

// la función solicita el array como puntero y el total de elementos
void mostrar(const int* array, const int& total) {
    cout << "Array de " << total << " elementos: ";
    int *i = new int; // puntero dinámico
    for (*i = 0; *i < total; *i += 1) {
        cout << array[*i] << ", ";
    }
    cout << "fin del array.\n";
    delete i; // libero el puntero dinámico (equivalente a free(*ptr) de C)
}

void cargar(int** array, const int& total) {
    for (int i = 0; i < total; i++) {
        (*array)[i] = 10 * (i + 1);
    }
}

int main() {
    int var = 283;
    int* p = &var;
    cout << "La variable \"var\" contiene: " << var << '\n';
    cout << "\"var\" se aloja en: " << p << '\n';
    int array[] = {89, 92, 24, 1}; // array normal
    int total = sizeof(array) / sizeof(array[0]); // solo se puede calcular en este ámbito.
    int* ap = array;
    mostrar(array, total);
    cout << "*puntero = " << ap << " -> array[0] : " << *ap << '\n';
    cout << "*puntero + 1 = " << (ap+1) << " -> array[1] : " << *(ap + 1) << '\n';
    int *ptrArray = new int[total];
    cargar(&ptrArray, total);
    mostrar(ptrArray, total);
    cout << "Fin del programa." << endl;
    delete ptrArray;
    return EXIT_SUCCESS;
}