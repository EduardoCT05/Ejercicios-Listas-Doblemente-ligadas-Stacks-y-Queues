#pragma once
#include "Figura.h"
#include <cmath>

class Circulo : public Figura {
private:
    float radio;

public:
    Circulo(float r)
        : Figura("Circulo"), radio(r) {}
    ~Circulo() override {}

    float CalcularArea() const override {
        return static_cast<float>(3.1416) * radio * radio;
    }

    float CalcularPerimetro() const override {
        return 2 * static_cast<float>(3.1416) * radio;
    }
};
