#include "Presion.h"

// Constructor, uno para float y otro para copia.
Presion::Presion(float presionEstatica, float presionDinamica, float tiempoMedicion) : 
    MedicionBase(tiempoMedicion),
    presionEstatica(presionEstatica),
    presionDinamica(presionDinamica) 
{}

Presion::Presion(const Presion& other) : 
    MedicionBase(other),
    presionEstatica(other.presionEstatica),
    presionDinamica(other.presionDinamica) 
{}

// Métodos para serializar y deserializar e imprimir.
void Presion::serializar(std::ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::imprimir() const {
    std::cout << "==================================" << std::endl;
    std::cout << "Datos de Presion:" << std::endl;
    std::cout << "    Presion Estatica: " << presionEstatica << std::endl;
    std::cout << "    Presion Dinamica: " << presionDinamica << std::endl;
    std::cout << "    Tiempo de Medicion: " << getTiempo() << std::endl;
    std::cout << "==================================" << std::endl;
}