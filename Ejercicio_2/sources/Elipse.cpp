#include "Elipse.h"

Elipse::Elipse(Punto& centro, float semi_Mayor, float semi_Menor) :
    centro(centro),
    semi_Mayor(semi_Mayor),
    semi_Menor(semi_Menor)
{}

void Elipse::setSemiMayor(float semi_Mayor) {this->semi_Mayor = semi_Mayor;}

void Elipse::setSemiMenor(float semi_Menor) {this->semi_Menor = semi_Menor;}

void Elipse::setCentro(Punto& centro) {this->centro = centro;}

float Elipse::getSemiMayor() const {return semi_Mayor;}

float Elipse::getSemiMenor() const {return semi_Menor;}

Punto Elipse::getCentro() const {return centro;}