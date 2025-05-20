#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include "Presion.h"
#include "Posicion.h"

class SaveFlightData {
public: 
    // Atributos de la clase SaveFlightData.
    Posicion posicion;
    Presion presion;

    // Constructor, uno para float y otro para copia, y Destructor.
    SaveFlightData(const Posicion& p, const Presion& q);
    SaveFlightData() = default;
    ~SaveFlightData() = default;

    // Métodos virtuales puros para serializar y deserializar e imprimir.
    void serializar(std::ofstream& out) const;
    void deserializar(std::ifstream& in);
    void imprimir();
};

#endif // FLIGHTDATA_H