#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Punto.h"

class Rectangulo{
private:
    Punto verticeIF;
    float ancho;
    float largo;

public:
    // Constructor y Destructor.
    Rectangulo(Punto& verticeIF, float ancho, float largo);
    ~Rectangulo() = default;

    // Setters.
    void setVerticeIF(Punto& verticeIF);
    void setAncho(float ancho);
    void setLargo(float largo);

    // Getters.
    Punto getVerticeIF() const;
    float getAncho() const;
    float getLargo() const;
};

#endif // RECTANGULO.H