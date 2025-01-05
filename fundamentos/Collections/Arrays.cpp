#include <iostream>

using namespace std;

void calcularPromedio(int array[], int total);

int main() {

    // los arrays son colecciones estáticas
    int array[] = {2, 5, 23, 539, 88, 0, 11};

    int total = sizeof(array) / sizeof(array[0]); // solo se puede calcular en este ámbito.

    calcularPromedio(array, total);

    cout << "\nFin del programa." << endl;
    
    return 0;
}

void calcularPromedio(int array[], int total) {
    int suma = 0;
    for (int i = 0; i < total; i++) {
        cout << array[i] << ", ";
        suma += array[i];
    }
    float promedio = static_cast<float>(suma) / total;
    cout << "el promedio es: " << promedio << '\n';
}