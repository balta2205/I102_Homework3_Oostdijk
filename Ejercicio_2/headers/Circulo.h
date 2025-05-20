#ifndef CIRCULO_H
#define CIRCULO_H

#include "Punto.h"

class Circulo {
private:
    Punto centro;
    float radio;
    
public:
    // Constructor y Destructor.
    Circulo(Punto& centro, float radio);
    ~Circulo() = default;

    // Setters.
    void setRadio(float radio);
    void setCentro(Punto& centro);

    // Getters.
    float getRadio() const;
    Punto getCentro() const;
};

#endif // CIRCULO.H