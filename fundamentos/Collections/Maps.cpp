#include <iostream>
#include <map>
#include <string>

using namespace std;

void nuevoContacto(map<string, string> *contactos);

void mostrar(const map<string, string> &contactos);

int main() {
    map<string, string> contactos;
    contactos = {
        {"+54 388 2371424", "Juan Perez"},
        {"+54 381 9232111", "Ana Cruz"},
        {"+54 11 2324090", "Enrique Fernández"}
    };
    mostrar(contactos);
    nuevoContacto(&contactos);
    mostrar(contactos);
    contactos.clear();
    cout << "Fin del programa." << endl;
    return 0;
}

void nuevoContacto(map<string, string> *contactos) {
    string nroTel, nombre;
    cout << "Ingrese un número: ";
    getline(cin, nroTel);
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    contactos->insert({nroTel, nombre});
}

void mostrar(const map<string, string> &contactos) {
    cout << '\t' << "Contactos: " << contactos.size() << '\n';
    for (const auto& item : contactos) {
        cout << "Teléfono: " << item.first << ", Nombre: " << item.second << '\n';
    }
    cout << "\tFin de la lista.\n";
}