#include "Posicion.h"

#include <iostream>
#include <fstream>

Posicion::Posicion(float latitud, float longitud, float altitud, float tiempoMedicion):
    MedicionBase(tiempoMedicion),
    latitud(latitud),
    longitud(longitud),
    altitud(altitud)
{}

Posicion::Posicion(const Posicion& other)
    : MedicionBase(other),
      latitud(other.latitud),
      longitud(other.longitud),
      altitud(other.altitud) {}

void Posicion::serializar(std::ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion::imprimir() const {
    std::cout << "==================================" << std::endl;
    std::cout << "Datos de Posicion:" << std::endl;
    std::cout << "    Latitud: " << latitud << std::endl;
    std::cout << "    Longitud: " << longitud << std::endl;
    std::cout << "    Altitud: " << altitud << std::endl;
    std::cout << "    Tiempo de medicion: " << getTiempo() << std::endl;
}