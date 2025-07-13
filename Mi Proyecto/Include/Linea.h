#pragma once
#include "Figura.h"
#include <stdexcept>

class Linea : public Figura {
private:
    float* segmentos;
    int    numSegmentos;

public:
    Linea(const float* arr, int n)
        : Figura("Linea"), numSegmentos(n) {
        if (n <= 0)
            throw std::invalid_argument("Número de segmentos inválido");
        segmentos = new float[n];
        for (int i = 0; i < n; ++i)
            segmentos[i] = arr[i];
    }

    ~Linea() override {
        delete[] segmentos;
    }

    float CalcularArea() const override {
        return 0.0f;
    }

    float CalcularPerimetro() const override {
        float sum = 0.0f;
        for (int i = 0; i < numSegmentos; ++i)
            sum += segmentos[i];
        return sum;
    }
};
