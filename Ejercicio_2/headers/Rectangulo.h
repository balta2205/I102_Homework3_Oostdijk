#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Punto.h"

class Rectangulo{
    private:
        Punto verticeIF;
        float ancho;
        float largo;
    public:
        Rectangulo(Punto& verticeIF, float ancho, float largo);
        ~Rectangulo() = default;
        void setVerticeIF(Punto& verticeIF);
        void setAncho(float ancho);
        void setLargo(float largo);
        Punto getVerticeIF() const;
        float getAncho() const;
        float getLargo() const;
};

#endif // RECTANGULO.H