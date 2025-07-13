#pragma once
#include "Figura.h"
#include <cmath>
#include <string>

class FiguraNLados : public Figura {
private:
    int   n;
    float lado;

public:
    FiguraNLados(int numLados, float l)
        : Figura("Figura " + std::to_string(numLados) + " lados")
        , n(numLados)
        , lado(l) {}
    ~FiguraNLados() override {}

    float CalcularArea() const override {
        return (n * lado * lado) /
               (4 * tan(static_cast<float>(3.1416) / n));
    }

    float CalcularPerimetro() const override {
        return n * lado;
    }
};
