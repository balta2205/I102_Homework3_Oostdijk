#include "Punto.h"

// Constructor de la clase Punto.
Punto::Punto(float x, float y) : x(x), y(y) {}

// Setters.
void Punto::setX(float x){this->x = x;}
void Punto::setY(float y){this->y = y;}

// Getters.
float Punto::getX() const {return x;}
float Punto::getY() const {return y;}