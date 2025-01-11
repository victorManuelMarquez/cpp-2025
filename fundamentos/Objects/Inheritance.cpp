#include <iostream>

using namespace std;

class Animal {
    public:
        virtual void comer()
        {
            cout << "El animal está comiendo.\n";
        }
        void emiteSonido(string sonido) {
            cout << "Este animal dice: " << sonido;
        }
};

class Vaca : public Animal {
    public:
        // sobreescribo la función de la clase padre
        void comer() override
        {
            cout << "El animal está pastando.\n";
        }
        // función propia de esta clase
        void muge()
        {
            emiteSonido("muuuu!\n");
        }
};

int main(void) {
    Vaca vaca;
    vaca.comer();
    vaca.muge();
    return EXIT_SUCCESS;
}