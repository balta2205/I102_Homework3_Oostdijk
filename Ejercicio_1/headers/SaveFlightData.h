#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include "Presion.h"
#include "Posicion.h"

class SaveFlightData {
public: 
    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& p, const Presion& q);
    SaveFlightData() = default;
    ~SaveFlightData() = default;

    void serializar(std::ofstream& out) const;
    void deserializar(std::ifstream& in);
    void imprimir();
};

#endif // FLIGHTDATA_H