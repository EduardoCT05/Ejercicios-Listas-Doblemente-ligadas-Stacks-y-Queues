#include <iostream>
#include "../include/LQueue.h"
#include "../include/LStack.h"
#include "../include/Circulo.h"
#include "../include/Cubo.h"
#include "../include/Linea.h"

int main() {
    LQueue<int> q;
    q.Enqueue(10);
    q.Enqueue(20);
    std::cout << "Dequeue Q: " << q.Dequeue() << "\n";

    LStack<std::string> s;
    s.Push("Hola");
    s.Push("Mundo");
    std::cout << "Pop S: " << s.Pop() << "\n";

    Circulo c(3.0f);
    std::cout << "Área Círculo: " << c.CalcularArea() << "\n";

    Cubo cube(2.0f);
    std::cout << "Volumen Cubo: " << cube.Volumen() << "\n";

    float segs[] = {1.0f, 2.0f, 3.0f};
    Linea linea(segs, 3);
    std::cout << "Perímetro Línea: " << linea.CalcularPerimetro() << "\n";

    return 0;
}
