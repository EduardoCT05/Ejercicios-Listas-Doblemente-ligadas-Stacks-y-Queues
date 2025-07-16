#pragma once

#include "Cuadrado.h"
#include <stdexcept>

/**
 * @brief Representa un cubo regular (todos sus lados iguales).
 * Hereda de Cuadrado para reutilizar la lógica de un lado.
 */
class Cubo : public Cuadrado {
public:
    /**
     * @param lado Longitud del arista del cubo (debe ser > 0).
     */
    explicit Cubo(float lado)
        : Cuadrado(lado)
    {
        if (lado <= 0.0f)
            throw std::invalid_argument("Cubo::Cubo(): el lado debe ser > 0");
    }

    /**
     * @brief Calcula el área de la superficie del cubo (6 caras).
     * @return Área total de la superficie.
     */
    float CalcularArea() const override {
        // 6 caras, cada una de área lado * lado
        return 6.0f * lado * lado;
    }

    /**
     * @brief Calcula la suma de todas las aristas del cubo (12 aristas).
     * @return Longitud total de las aristas.
     */
    float CalcularPerimetro() const override {
        return 12.0f * lado;
    }

    /**
     * @brief Volumen del cubo (lado^3).
     * @return Volumen.
     */
    float Volumen() const {
        return lado * lado * lado;
    }

    /**
     * @brief Alias para superficie: misma información que CalcularArea().
     * @return Área de la superficie.
     */
    float Surface() const {
        return CalcularArea();
    }
};
