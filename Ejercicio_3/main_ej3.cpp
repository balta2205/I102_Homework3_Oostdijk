#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <type_traits>

/*
La clase Clase1<T> permite almacenar una colección de objetos del tipo T y convertirlos 
en una cadena de texto con formato específico según el tipo (double, string o vector<int>). 
Para esto utiliza plantillas y una evaluación en tiempo de compilación con `if constexpr` 
para personalizar la forma en que se genera la representación textual. La clase Clase2 mantiene 
pares de etiquetas y datos, y se encarga de construir una cadena JSON válida con todas las etiquetas y sus respectivos datos. 
*/

template <typename T>
class Clase1 {
private:
    std::vector<T> cosas;

public:
    void agregarCosa(const T& cosa) {cosas.push_back(cosa);} // Agregar un elemento al vector.

    std::string generarDatos() const {
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

class Clase2 {
private:
    std::vector<std::pair<std::string, std::string>> etiquetas_datos;

public:
    template <typename T>
    void agregarEtiquetas(const std::string& etiqueta, const Clase1<T>& cosas) { // Agregar el par de etiqueta y dato a la lista de etiquetas.
        etiquetas_datos.push_back(std::make_pair(etiqueta, cosas.generarDatos()));
    }

    void generarJSON() { // Generar el JSON a partir de los datos.
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

int main() {
    // Creo el contenedor de datos de tipo double y le agrego datos.
    Clase1<double> cosas_1;
    cosas_1.agregarCosa(1.3);
    cosas_1.agregarCosa(2.1);
    cosas_1.agregarCosa(3.2);

    // Creo el contenedor de datos de tipo string y le agrego datos.
    Clase1<std::string> cosas_2;
    cosas_2.agregarCosa("Hola");
    cosas_2.agregarCosa("Mundo");

    // Creo el contenedor de datos de tipo vector<int> y le agrego datos.
    Clase1<std::vector<int>> cosas_3;
    cosas_3.agregarCosa({1, 2});
    cosas_3.agregarCosa({3, 4});

    // Creo el contenedor de etiquetas que se encarga de generar el JSON y le agrego cada "lista de cosas".
    Clase2 etiquetas;
    etiquetas.agregarEtiquetas("vec_doubles", cosas_1);
    etiquetas.agregarEtiquetas("palabras", cosas_2);
    etiquetas.agregarEtiquetas("listas", cosas_3);

    // Genero el JSON y lo imprimo.
    etiquetas.generarJSON();

    return 0;
}
