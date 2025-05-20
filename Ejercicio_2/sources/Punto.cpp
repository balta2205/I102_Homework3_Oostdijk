#include "Punto.h"

Punto::Punto(float x, float y) : x(x), y(y) {}

void Punto::setX(float x){this->x = x;}

void Punto::setY(float y){this->y = y;}

float Punto::getX() const {return x;}

float Punto::getY() const {return y;}