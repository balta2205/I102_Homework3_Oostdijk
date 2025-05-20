#ifndef PROCESADORFIGURA_H
#define PROCESADORFIGURA_H

#include <iostream>
#include "Rectangulo.h"
#include "Circulo.h"
#include "Elipse.h"

#define PI 3.14159265358979323846

template <typename T>
class ProcesadorFigura {
    public:
        void Area(T&) {
            std::cout << "ERROR: No es posible calcular area." << std::endl;
        }
};

template <>
class ProcesadorFigura<Circulo>{
    public:
        void Area(Circulo& circulo){
            std::cout << "Area del circulo: " << circulo.getRadio() * circulo.getRadio() * PI << std::endl;
        }
};

template <>
class ProcesadorFigura<Elipse>{
    public:
        void Area(Elipse& elipse){
            std::cout << "Area de la elipse: " << elipse.getSemiMayor() * elipse.getSemiMenor() * PI << std::endl;
        }
};

template <>
class ProcesadorFigura<Rectangulo>{
    public:
        void Area(Rectangulo& rectangulo){
            std::cout << "Area del rectangulo: " << rectangulo.getAncho() * rectangulo.getLargo() << std::endl;
        }
};

#endif // PROCESADORFIGURA.H