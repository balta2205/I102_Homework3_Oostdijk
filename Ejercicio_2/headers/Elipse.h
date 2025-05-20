#ifndef ELIPSE_H
#define ELIPSE_H

#include "Punto.h"

class Elipse{
private:
    Punto centro;
    float semi_Mayor;
    float semi_Menor;

public:
    // Constructor y Destructor.
    Elipse(Punto& centro, float semi_Mayor, float semi_Menor);
    ~Elipse() = default;

    // Setters.
    void setSemiMayor(float semi_Mayor);
    void setSemiMenor(float semi_Menor);
    void setCentro(Punto& centro);

    // Getters.
    float getSemiMayor() const;
    float getSemiMenor() const;
    Punto getCentro() const;
};

#endif // ELIPSE.H