#include "Circulo.h"

Circulo::Circulo(Punto& centro, float radio) : centro(centro), radio(radio) {}

void Circulo::setCentro(Punto& centro) {this->centro = centro;}

void Circulo::setRadio(float radio) {this->radio = radio;}

Punto Circulo::getCentro() const {return centro;}

float Circulo::getRadio() const {return radio;}