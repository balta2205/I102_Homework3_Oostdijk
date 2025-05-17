#include "MedicionBase.h"

#include <iostream>
#include <fstream>

MedicionBase::MedicionBase(float tiempoMedicion): 
    tiempoMedicion(std::make_unique<float>(tiempoMedicion)) {
}

MedicionBase::MedicionBase(const MedicionBase& other)
    : tiempoMedicion(std::make_unique<float>(*other.tiempoMedicion)) {}

float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
} 

void MedicionBase::serializar(std::ofstream& out) const {    
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::deserializar(std::ifstream& in){
    tiempoMedicion = std::make_unique<float>(0);
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}