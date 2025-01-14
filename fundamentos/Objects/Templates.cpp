#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <sstream>

// clase padre
// plantilla de clase
template <typename T>
class Figura {
    // visibilidad en clases hijas
    protected:
        std::string nombre = {"\"Desconocida\""};
    // constructor por defecto
    public:
        Figura(std::string nombre) : nombre(nombre) {};
    public:
        // funciones que serán redefinidas en otras clases
        virtual T area() const
        {
            return 0; // valor inocuo
        }

        virtual T perimetro() const
        {
            return 0; // valor inocuo
        }

        // función que podría ser redefinida en clases hijas
        virtual std::string getNombre() const {
            return nombre;
        }
};

template <typename T>
class Circulo final : public Figura<T> {
    public:
        Circulo(const T radio) : Figura<T>("Círculo"), radio(radio) {};
    private:
        float radio;
    public:
        virtual std::string getNombre() const {
            std::stringstream stream;
            int valorEntero = static_cast<int>(radio);
            if (std::abs(radio - valorEntero > 0.001)) {
                stream << std::fixed << std::setprecision(2) << radio;
            } else {
                stream << valorEntero;
            }
            return this->nombre + " de radio " + stream.str();
        }

        virtual T area() const override
        {
            std::cout.precision(3);
            return M_PI * (radio * radio);
        }

        virtual T perimetro() const override
        {
            std::cout.precision(3);
            return radio * 2 * M_PI; // en algunas plataformas antígüas es necesario más configuración
        }
};

int main(void) {
    // polimorfismo
    Figura<float>* circulo = new Circulo(6.0f);
    std::cout << "EL área de un " << circulo->getNombre() << " es " << circulo->area() << '\n';
    std::cout << "El perímetro de un " << circulo->getNombre() << " es " << circulo->perimetro() << std::endl;
    delete circulo;
    return EXIT_SUCCESS;
}