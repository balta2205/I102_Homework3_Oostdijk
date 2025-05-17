#ifndef PRESION_H
#define PRESION_H

#include "MedicionBase.h"

class Presion : public MedicionBase{
public:
    float presionEstatica;
    float presionDinamica;

    Presion(float p = 0, float q = 0, float t = 0);
    Presion(const Presion& other);
    ~Presion() = default;

    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};

#endif // PRESION_H