#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Ingrese una frase: ";
    std::getline(std::cin, str);
    std::cout << "Ingresó la frase \"" << str << "\"\nFin del Programa.\n";
    return 0;
}