#ifndef CLASE_1_H
#define CLASE_1_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <type_traits>


template <typename T>
class Clase1 {
private:
    std::vector<T> cosas;

public:
    Clase1() = default; // Constructor por defecto.
    ~Clase1() = default; // Destructor por defecto.

    void agregarCosa(const T& cosa) {cosas.push_back(cosa);} // Agregar un elemento al vector.

    std::string generarDatos() const { // Generar una cadena de texto con los datos almacenados.
        if (cosas.empty()) {return "\"No hay datos para generar.\"";} // Si no hay datos, retornar un mensaje de que no hay datos.

        else if constexpr (std::is_same_v<T, double>) { // Si el tipo es double, retornar un string con los datos.
            std::ostringstream ss;
            ss << "[";
            for (size_t i = 0; i < cosas.size(); ++i) { // Iterar sobre los doubles.
                ss << cosas[i];
                if (i != cosas.size() - 1) ss << ", "; // Si no es el ultimo elemento, agregar una coma.
            }
            ss << "]";
            return ss.str();
        }

        else if constexpr (std::is_same_v<T, std::string>) { // Si el tipo es string, retornar un string con los datos.
            std::ostringstream ss;
            ss << "[";
            for (size_t i = 0; i < cosas.size(); ++i) { // Iterar sobre los strings.
                ss << "\"" << cosas[i] << "\"";
                if (i != cosas.size() - 1) ss << ","; // Si no es el ultimo elemento, agregar una coma.
            }
            ss << "]";
            return ss.str();
        }

        else if constexpr (std::is_same_v<T, std::vector<int>>) { // Si el tipo es vector<int>, retornar un string con los datos.
            std::ostringstream ss;
            ss << "[\n\t   ";
            for (size_t i = 0; i < cosas.size(); ++i) { // Iterar sobre los vectores de ints.
                ss << "[";
                for (size_t j = 0; j < cosas[i].size(); ++j) { // Iterar sobre los ints de cada vector.
                    ss << cosas[i][j];
                    if (j != cosas[i].size() - 1) ss << ","; // Si no es el ultimo elemento, agregar una coma.
                }
                ss << "]";
                if (i != cosas.size() - 1) ss << ",\n\t   "; // Si no es el ultimo elemento, agregar una coma y un salto de linea.
            }
            ss << "\n\t   ]";
            return ss.str();
        }
        else {return "\"Tipo de dato no soportado\"";} // Si no hay template para el tipo de dato, retornar un mensaje de que no soporta ese dato.
    }
};

#endif // CLASE_1_H