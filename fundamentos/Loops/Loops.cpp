#include <iostream>
#include <string>

using namespace std;

int main() {

    int loops = 10;
    string endLoop = "end for";

    cout << "For loop ciclando " << loops << " veces: ";

    for (int i = 0; i < loops; i++) {
        cout << i << ", ";
    }

    cout << endLoop;

    cout << "\nFor each ciclando \"" << endLoop << "\" string: ";

    for (char c : endLoop) {
        cout << "[" << c << "]";
    }

    cout << ' ' << endLoop;

    cout << "\nFor con doble variable: ";

    for (int i = loops, j = loops * -1; i != j; i--, j++) {
        cout << "i = " << i << " <<>> j = " << j << "\n\t";
    }

    cout << '\r' << endLoop;

    endLoop = "end while";

    cout << "\nWhile loop ciclando " << loops << " veces:\n";

    int loop = 1;
    while (loop <= loops) {
        cout << "\tciclo " << loop << " de " << loops << '\n';
        loop++;
    }

    cout << endLoop;

    endLoop = "end do";

    cout << "\nCiclando...";

    loop = 0;
    string dato;

    do {
        loop++;
        cout << "\nIngrese \"fin\" para salir del bucle: ";
        getline(cin, dato);
        cout << "Ingresó " << dato << " | vuelta " << loop;
    } while (dato != "fin");

    cout << '\n' << endLoop;

    cout << "\nFin del programa.\n";

    return 0;
}