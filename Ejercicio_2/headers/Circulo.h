#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"

class Circulo {
    private:
        Punto centro;
        float radio;
    public:
        Circulo(Punto& centro, float radio);
        ~Circulo() = default;
        void setRadio(float radio);
        void setCentro(Punto& centro);
        float getRadio() const;
        Punto getCentro() const;
};

#endif // CIRCULO.H