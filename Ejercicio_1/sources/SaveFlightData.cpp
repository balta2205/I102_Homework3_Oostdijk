#include "SaveFlightData.h"

// Constructor.
SaveFlightData::SaveFlightData(const Posicion& posicion, const Presion& presion) :
    posicion(posicion),
    presion(presion)
{}

// Métodos para serializar y deserializar e imprimir.
void SaveFlightData::serializar(std::ofstream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() {
    posicion.imprimir();
    presion.imprimir();
}