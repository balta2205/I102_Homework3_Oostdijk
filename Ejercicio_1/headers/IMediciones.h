#ifndef IMEDICIONES_H
#define IMEDICIONES_H

#include <iostream>
#include <fstream>

class IMediciones {
public:
    virtual ~IMediciones() = default; 
    virtual void serializar(std::ofstream& out) const = 0;
    virtual void deserializar(std::ifstream& in) = 0; 
};

#endif // IMEDICIONES_H

