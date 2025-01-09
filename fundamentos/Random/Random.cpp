#include <iostream>

using namespace std;

int generarNro(const int& rango, const int& desface = 0) {
    if (rango == 0)
        throw runtime_error("rango == 0");
    else if (desface < 0)
        throw runtime_error("rango negativo.");
    else if (desface >= rango)
        throw runtime_error("desface igual o mayor a rango.");
    if (desface > 0)
        return desface + (rand() % (rango - desface + 1));
        //Ejemplo: 100 + (rand() % (200-100+1) => [0 - 100]) => 100 + [0 - 100] => 100 - 200
    else
        return rand() % (rango + 1); // rand() % (10 + 1) => 0 - 10
}

int main(void) {
    srand(time(0)); // semilla aleatoria
    int random = generarNro(15, 2);
    cout << "A continuación se van a generar " << random << " números: ";
    for (int i = 0; i < random; i++) {
        cout << generarNro(1000) << ", ";
    }
    cout << "Fin del programa." << endl;
    return EXIT_SUCCESS;
}