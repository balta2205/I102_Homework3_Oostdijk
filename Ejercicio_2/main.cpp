#include "ProcesadorFigura.h"

int main(){
    // Creo puntos para las figuras.
    Punto p1(0.0, 0.0);
    Punto p2(1.1, 1.1);
    Punto p3(2.2, 2.2);

    // Creo las figuras en base a los puntos.
    Circulo circulo(p1, 5.0);
    Elipse elipse(p2, 3.0, 4.0);
    Rectangulo rectangulo(p2, 5.0, 8.0);

    // Creo el procesador de figuras.
    ProcesadorFigura<Punto> procesadorPunto;
    ProcesadorFigura<Circulo> procesadorCirculo;
    ProcesadorFigura<Elipse> procesadorElipse;
    ProcesadorFigura<Rectangulo> procesadorRectangulo;

    // Calculo area del punto para que de error y entre al caso generico.
    std::cout << "===================================" << std::endl;
    procesadorPunto.Area(p1);
    std::cout << "===================================" << std::endl;

    // Calculo las areas de cada figura.
    std::cout << "\nAreas del ejercicio 2:" << std::endl;
    std::cout << "===========================" << std::endl;
    procesadorCirculo.Area(circulo);
    std::cout << "===========================" << std::endl;
    procesadorElipse.Area(elipse);
    std::cout << "===========================" << std::endl;
    procesadorRectangulo.Area(rectangulo);
    std::cout << "===========================\n" << std::endl;

    return 0;
}