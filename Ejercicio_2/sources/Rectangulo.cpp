#include "Rectangulo.h"

// Constructor de la clase Rectangulo.
Rectangulo::Rectangulo(Punto& verticeIF, float ancho, float largo) : 
    verticeIF(verticeIF),
    ancho(ancho),
    largo(largo) 
{}

// Setters.
void Rectangulo::setVerticeIF(Punto& verticeIF) {this->verticeIF = verticeIF;}
void Rectangulo::setAncho(float ancho) {this->ancho = ancho;}
void Rectangulo::setLargo(float largo) {this->largo = largo;}

// Getters.
Punto Rectangulo::getVerticeIF() const {return verticeIF;}
float Rectangulo::getAncho() const {return ancho;}
float Rectangulo::getLargo() const {return largo;}