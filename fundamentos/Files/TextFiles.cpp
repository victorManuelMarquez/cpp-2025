#include <iostream>
#include <fstream>
#include <cstdlib>

void leerArchivo(std::ifstream* inputStream);

int main(void) {
    // escritura
    std::string nombre = "archivo.txt";
    std::ofstream salida;
    salida.open(nombre);
    salida << "En c++ se puede almacenar el contenido como si fuera un stream de salida por pantalla.\n";
    salida << "Fin del archivo.";
    std::cout << "Se ha escrito el archivo \"" + nombre + "\"\n";
    salida.close();
    // lectura
    std::ifstream entrada;
    entrada.open(nombre);
    if (entrada.is_open()) {
        leerArchivo(&entrada);
        entrada.close();
    } else {
        std::cout << "No se pudo abrir el archivo.\n";
    }
    std::cout << "Fin del programa." << std::endl;
    return EXIT_SUCCESS;
}

void leerArchivo(std::ifstream* inputStream) {
    std::string line;
    while (std::getline(*inputStream, line)) {
        std::cout << line << std::endl;
    }
}