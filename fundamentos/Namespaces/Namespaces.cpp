#include <iostream>

// todos los elementos de este espacio estarán disponibles
// tener especial cuidado en proyectos grandes
using namespace std;

namespace primerespacio {
    int x = 130;
    int y = -240;
}

namespace segundoespacio {
    int x = -2;
    int y = 100;
}

float x = 3.14;

int main() {
    using namespace segundoespacio;
    cout << "x = " << primerespacio::x << '\n'; // invoco x del primer espacio
    cout << "y = " << primerespacio::y << '\n';
    cout << "X = " << segundoespacio::x << '\n';
    cout << "Y = " << y << '\n'; // importada del segundo espacio
    cout << "global x = " << ::x << '\n'; // ámbito de namespace global (por defecto)
    return 0;
}