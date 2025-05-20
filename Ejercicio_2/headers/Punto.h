#ifndef PUNTO_H 
#define PUNTO_H

class Punto {
    private:
        float x;
        float y;
    public: 
        Punto(float x, float y);
        ~Punto() = default;
        void setX(float x);
        void setY(float y);
        float getX() const;
        float getY() const;
};

#endif // PUNTO.H