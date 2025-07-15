// Cubo.h
#pragma once
#include "Figura.h"
#include <stdexcept>

class Cubo : public Figura {
private:
    float lado;

public:
    Cubo(float l)
        : Figura("Cubo"), lado(l)
    {
        if (l <= 0.0f)
            throw std::invalid_argument("Cubo::Cubo(): el lado debe ser > 0");
    }

    // Área total = 6 caras * (lado × lado)
    float CalcularArea() const override {
        return 6.0f * lado * lado;
    }

    // Perímetro total = 12 aristas * lado
    float CalcularPerimetro() const override {
        return 12.0f * lado;
    }
};
