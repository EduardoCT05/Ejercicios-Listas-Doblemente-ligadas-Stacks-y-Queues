#pragma once
#include <string>

class Figura {
protected:
    std::string nombre;

public:
    Figura(const std::string& name)
        : nombre(name) {}

    virtual ~Figura() {}

    virtual float CalcularArea() const = 0;
    virtual float CalcularPerimetro() const = 0;

    const std::string& ObtenerNombreDeFigura() const {
        return nombre;
    }
};
