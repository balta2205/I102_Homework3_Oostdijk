#ifndef PUNTO_H 
#define PUNTO_H

class Punto {
private:
    float x;
    float y;

public: 
    // Constructor y Destructor.
    Punto(float x, float y);
    ~Punto() = default;

    // Setters.
    void setX(float x);
    void setY(float y);

    // Getters.
    float getX() const;
    float getY() const;
};

#endif // PUNTO.H