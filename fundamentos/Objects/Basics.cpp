#include <iostream>

using namespace std;

// clase sin constructor declarado
class ClaseHM {
    // función
    public:
        string getMessage() const
        {
            return "¡Hola Mundo!";
        }
} holaMundo; // instancia la clase y está activa desde este punto

// clase con constructores, funciones y encapsulamiento
class ClaseAritmeticaBasica {
    // atributos
    private:
        int x, y;
    // constructores
    public:
        // Constructor por defecto explícito
        ClaseAritmeticaBasica() {
            cout << "Artiméticas: x = " << this->x << " & y = " << this->y << '\n';
        }

        // Constructor definido
        ClaseAritmeticaBasica(int x, int y) : x(x), y(y) {}
    // funciones
    public:
        int suma() const
        {
            return this->x + this->y;
        }

        int resta() const
        {
            return this->x - this->y;
        }

        int producto() const
        {
            return this->x * this->y;
        }

        float division() const
        {
            if (y == 0) {
                throw runtime_error("División por 0");
            }
            return (float) this->x / (float) this->y;
        }
    // setters
    public:
        int getX() const {
            return this->x;
        }

        void setX(int value) {
            cout << "Estableciendo X: " << value << '\n'; // notifico el nuevo valor
            this->x = value;
        }

        int getY() const {
            return this->y;
        }

        void setY(int value) {
            cout << "Estableciendo Y: " << value << '\n'; // notifico el nuevo valor
            this->y = value;
        }
} aritmeticas; // instacio la clase para usar los setters y getters

int main(void) {
    cout << holaMundo.getMessage() << endl;
    aritmeticas.setX(12);
    aritmeticas.setY(24);
    cout << "Suma entre: " << aritmeticas.getX() << " y " << aritmeticas.getY() << " = " << aritmeticas.suma() << '\n';
    cout << "Resta entre: " << aritmeticas.getX() << " y " << aritmeticas.getY() << " = " << aritmeticas.resta() << '\n';
    cout << "Producto entre: " << aritmeticas.getX() << " y " << aritmeticas.getY() << " = " << aritmeticas.producto() << '\n';
    cout << "División entre: " << aritmeticas.getX() << " y " << aritmeticas.getY() << " = " << aritmeticas.division() << '\n';
    ClaseAritmeticaBasica basica(18, 2);
    cout << "Más cálculos...\n";
    cout << "Suma entre: " << basica.getX() << " y " << basica.getY() << " = " << basica.suma() << '\n';
    cout << "Resta entre: " << basica.getX() << " y " << basica.getY() << " = " << basica.resta() << '\n';
    cout << "Producto entre: " << basica.getX() << " y " << basica.getY() << " = " << basica.producto() << '\n';
    cout << "División entre: " << basica.getX() << " y " << basica.getY() << " = " << basica.division() << '\n';
    return EXIT_SUCCESS;
}