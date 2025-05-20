#ifndef IMEDICIONES_H
#define IMEDICIONES_H

#include <memory>
#include <iostream>
#include <fstream>

class IMediciones {
public:
    // Destructor.
    virtual ~IMediciones() = default; 

    // Métodos virtuales puros para serializar y deserializar.
    virtual void serializar(std::ofstream& out) const = 0;
    virtual void deserializar(std::ifstream& in) = 0; 
};

#endif // IMEDICIONES_H

