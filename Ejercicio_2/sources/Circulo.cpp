#include "Circulo.h"

// Constructor de la clase Circulo.
Circulo::Circulo(Punto& centro, float radio) : centro(centro), radio(radio) {}

// Setters.
void Circulo::setCentro(Punto& centro) {this->centro = centro;}
void Circulo::setRadio(float radio) {this->radio = radio;}

// Getters.
Punto Circulo::getCentro() const {return centro;}
float Circulo::getRadio() const {return radio;}