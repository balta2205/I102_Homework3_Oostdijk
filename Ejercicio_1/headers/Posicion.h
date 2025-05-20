#ifndef POSICION_H
#define POSICION_H

#include "MedicionBase.h"

class Posicion : public MedicionBase{
public: 
    // Atributos de la clase Posicion.
    float latitud;
    float longitud;
    float altitud;

    // Constructor, uno para float y otro para copia, y Destructor.
    Posicion(float lat = 0, float lon = 0, float alt = 0, float t = 0);
    Posicion(const Posicion& other);
    ~Posicion() = default;

    // Métodos virtuales puros para serializar y deserializar e imprimir.
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};

#endif // POSICION_H

