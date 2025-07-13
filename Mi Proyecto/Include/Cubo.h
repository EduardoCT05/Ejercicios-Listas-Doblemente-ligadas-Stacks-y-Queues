#pragma once
#include "Cuadrado.h"

class Cubo : public Cuadrado {
public:
    Cubo(float l)
        : Cuadrado(l) {
        nombre = "Cubo";
    }
    ~Cubo() override {}

    float Volumen() const {
        return lado * lado * lado;
    }

    float Surface() const {
        return 6 * lado * lado;
    }
};
