#include <iostream>
#include <cstdlib>

// clase padre
class Figura {
    private:
        std::string nombre = {"\"Desconocida\""};
    public:
        Figura() = default;
        Figura(std::string nombre) : nombre(nombre) {};
    
    public:
        // polimorfismo dinámico
        virtual float perimetro() const
        {
            return 0;
        }

        // esta función no es accesible desde una referencia de esta clase sin hacer casting dinámico
        std::string getNombre() {
            return nombre;
        }
};

// clase hija
class Rectagulo : public Figura {
    protected:
        int ancho, alto;
    public:
        Rectagulo() = default;
        // no se recomienda el uso de valores predeterminados en constructores
        Rectagulo(int ancho, int alto, std::string nombre = "\"Rectágulo\""):
            Figura(nombre), ancho(ancho), alto(alto) {};
    public:
        virtual float perimetro() const
        {
            return static_cast<float>(2 * (ancho + alto));
        }
        int getAncho() {
            return ancho;
        }
        int getAlto() {
            return alto;
        }
        std::string medidas() const
        {
            return " " + std::to_string(ancho) + 'x' + std::to_string(alto);
        }
};

// clase derivada
class Cuadrado : public Rectagulo {
    public:
        Cuadrado() = default;
        Cuadrado(int lado, std::string nombre = "\"Cuadrado\""):
            Rectagulo(lado, lado, nombre) {};
    public:
        virtual float perimetro() const
        {
            return static_cast<float>(ancho * alto);
        }
};

void calcularPerimetroDe(const Figura* f);

int main(void) {
    // uso normal de un objeto
    Rectagulo r(8, 4);
    std::cout << "Perímetro de un " << r.getNombre() << r.medidas() << " = " << r.perimetro() << '\n';
    // polimorfismo en tiempo de ejecución
    Cuadrado c(12); // instancia de cuadrado
    Figura* f = &c; // asigno la referencia
    // no se puede llamar a la función de la clase hija usando la referencia a la clase base
    calcularPerimetroDe(f);
    std::cout << "Perímetro de un " << c.getNombre() << c.medidas() << " = " << c.perimetro() << '\n';
    std::cout << "Fin del programa." << std::endl;
    // si empleara punteros con new se debe invocar delete *puntero y luego *puntero = nullptr
    return EXIT_SUCCESS;
}

void calcularPerimetroDe(const Figura* f) {
    // polimorfismo estático
    std::cout << "el perímetro de la figura es de " << f->perimetro() << '\n';
}