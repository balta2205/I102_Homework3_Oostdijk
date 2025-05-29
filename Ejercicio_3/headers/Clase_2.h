#ifndef CLASE_2_H
#define CLASE_2_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <type_traits>

class Clase2 {
private:
    std::vector<std::pair<std::string, std::string>> etiquetas_datos;

public:
    Clase2() = default; // Constructor por defecto.
    ~Clase2() = default; // Destructor por defecto.

    template <typename T>
    void agregarEtiquetas(const std::string& etiqueta, const Clase1<T>& cosas){ // Agregar el par de etiqueta y dato a la lista de etiquetas.
        etiquetas_datos.push_back(std::make_pair(etiqueta, cosas.generarDatos()));
    } 

    void generarJSON(){ // Generar el JSON a partir de los datos.
        std::ostringstream ss;
        ss << "{";
        for (size_t i = 0; i < etiquetas_datos.size(); ++i) { // Iterar sobre los datos.
            ss << " \"" << etiquetas_datos[i].first << "\" : " << etiquetas_datos[i].second;
            if (i != etiquetas_datos.size() - 1) {ss << ",";} // Si no es el ultimo elemento, agregar una coma.
            ss << "\n ";
        }
        ss << "\b}";
        std::cout << ss.str() << std::endl;
    }
};

#endif // CLASE_2_H