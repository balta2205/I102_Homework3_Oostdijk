#ifndef MEDICIONBASE_H
#define MEDICIONBASE_H

#include "IMediciones.h"
#include <memory>

class MedicionBase : public IMediciones {
protected: 
    std::unique_ptr<float> tiempoMedicion;

public:
    MedicionBase(float tiempoMedicion);
    MedicionBase(const MedicionBase& other);
    virtual ~MedicionBase() = default;

    virtual void serializar(std::ofstream& out) const override;
    virtual void deserializar(std::ifstream& in) override;

    float getTiempo() const;
    virtual void imprimir() const = 0;
};

#endif // MEDICIONBASE_H

