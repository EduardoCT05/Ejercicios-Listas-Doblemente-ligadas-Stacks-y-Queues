#include <iostream>
#include <stdexcept>
#include "../include/LQueue.h"
#include "../include/LStack.h"
#include "../include/Circulo.h"
#include "../include/Cubo.h"
#include "../include/Linea.h"
#include "../include/Figura.h"

int main() {
    // Cola y pila (ya estaban bien)
    LQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    std::cout << "Dequeue Q: " << q.Dequeue() << "\n";

    LStack<std::string> s;
    s.Push("Hola");
    s.Push("Mundo");
    std::cout << "Pop S: " << s.Pop() << "\n";

    try {
        // Círculo a través de puntero Figura*
        Figura* figura = new Circulo(3.0f);
        std::cout << "Área Círculo: " << figura->CalcularArea() << "\n";
        delete figura;

        // Cubo a través de puntero
        figura = new Cubo(2.0f);
        std::cout << "Área Cubo: " << figura->CalcularArea() << "\n";
        std::cout << "Perímetro Cubo: " << figura->CalcularPerimetro() << "\n";
        delete figura;

        // Línea a través de puntero
        float segs[] = {1.0f, 2.0f, 3.0f};
        figura = new Linea(segs, 3);
        std::cout << "Perímetro Línea: " << figura->CalcularPerimetro() << "\n";
        delete figura;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
