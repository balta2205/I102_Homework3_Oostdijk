#ifndef MEDICIONBASE_H
#define MEDICIONBASE_H

#include "IMediciones.h"

class MedicionBase : public IMediciones {
protected: 
    std::unique_ptr<float> tiempoMedicion;

public:
    // Constructor, uno para float y otro para copia, y Destructor.
    MedicionBase(float tiempoMedicion);
    MedicionBase(const MedicionBase& other);
    virtual ~MedicionBase() = default;

    // Métodos virtuales puros para serializar y deserializar.
    virtual void serializar(std::ofstream& out) const override;
    virtual void deserializar(std::ifstream& in) override;

    // Getter.
    float getTiempo() const;

    // Metodo para imprimir.
    virtual void imprimir() const = 0;
};

#endif // MEDICIONBASE_H

