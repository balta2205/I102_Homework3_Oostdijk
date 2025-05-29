#ifndef PROCESADORFIGURA_H
#define PROCESADORFIGURA_H

#include <iostream>
#include "Rectangulo.h"
#include "Circulo.h"
#include "Elipse.h"

#define PI 3.14159265358979323846  // Definicion de PI

template <typename T> 
class ProcesadorFigura { // Clase generica para procesar figuras.
    public:
        void Area(T&) {std::cout << "ERROR: No es posible calcular area." << std::endl;}
};

template <>
class ProcesadorFigura<Circulo>{ // Especializacion de la clase ProcesadorFigura para Circulo.
    public:
        // Sigue la formula: Area = radio * radio * PI.
        void Area(Circulo& circulo) {std::cout << "Area del circulo: " << circulo.getRadio() * circulo.getRadio() * PI << std::endl;}
};

template <>
class ProcesadorFigura<Elipse>{ // Especializacion de la clase ProcesadorFigura para Elipse.
    public:
        // Sigue la formula: Area = semiMayor * semiMenor * PI.
        void Area(Elipse& elipse) {std::cout << "Area de la elipse: " << elipse.getSemiMayor() * elipse.getSemiMenor() * PI << std::endl;}
};

template <>
class ProcesadorFigura<Rectangulo>{ // Especializacion de la clase ProcesadorFigura para Rectangulo.
    public:
        // Sigue la formula: Area = ancho * largo.
        void Area(Rectangulo& rectangulo) {std::cout << "Area del rectangulo: " << rectangulo.getAncho() * rectangulo.getLargo() << std::endl;}
};

template <typename T>
class Procesador {
    public:
        void Area(T& figura) { // Metodo para calcular el area de la figura.
            if constexpr (std::is_same_v<T, Circulo>){
                std::cout << "Area del circulo: " << figura.getRadio() * figura.getRadio() * PI << std::endl;
            }
            else if constexpr (std::is_same_v<T, Elipse>){
                std::cout << "Area de la elipse: " << figura.getSemiMayor() * figura.getSemiMenor() * PI << std::endl;
            }
            else if constexpr (std::is_same_v<T, Rectangulo>){
                std::cout << "Area del rectangulo: " << figura.getAncho() * figura.getLargo() << std::endl;
            }
            else {
                std::cout << "ERROR: No es posible calcular area." << std::endl;
            }
        }
};


#endif // PROCESADORFIGURA.H