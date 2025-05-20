#ifndef PRESION_H
#define PRESION_H

#include "MedicionBase.h"

class Presion : public MedicionBase{
public:
    // Atributos de la clase Presion.
    float presionEstatica;
    float presionDinamica;
    
    // Constructor, uno para float y otro para copia, y Destructor.
    Presion(float p = 0, float q = 0, float t = 0);
    Presion(const Presion& other);
    ~Presion() = default;

    // Métodos virtuales puros para serializar y deserializar e imprimir.
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};

#endif // PRESION_H