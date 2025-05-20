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
    void agregarCosa(const T& cosa) {
        cosas.push_back(cosa);
    }

    std::string generarDatos() const {
        if (cosas.empty()) {
            return "\"No hay datos para generar.\"";
        }
        else if constexpr (std::is_same_v<T, double>) {
            std::ostringstream ss;
            ss << "[";
            for (size_t i = 0; i < cosas.size(); ++i) {
                ss << cosas[i];
                if (i != cosas.size() - 1) ss << ", ";
            }
            ss << "]";
            return ss.str();
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            std::ostringstream ss;
            ss << "[";
            for (size_t i = 0; i < cosas.size(); ++i) {
                ss << "\"" << cosas[i] << "\"";
                if (i != cosas.size() - 1) ss << ",";
            }
            ss << "]";
            return ss.str();
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            std::ostringstream ss;
            ss << "[\n\t   ";
            for (size_t i = 0; i < cosas.size(); ++i) {
                ss << "[";
                for (size_t j = 0; j < cosas[i].size(); ++j) {
                    ss << cosas[i][j];
                    if (j != cosas[i].size() - 1) ss << ",";
                }
                ss << "]";
                if (i != cosas.size() - 1) ss << ",\n\t   ";
            }
            ss << "\n\t   ]";
            return ss.str();
        }
        else {
            return "\"Tipo de dato no soportado\"";
        }
    }
};

class Clase2 {
private:
    std::vector<std::pair<std::string, std::string>> etiquetas_datos;

public:
    template <typename T>
    void agregarEtiquetas(const std::string& etiqueta, const Clase1<T>& cosas) {
        etiquetas_datos.push_back(std::make_pair(etiqueta, cosas.generarDatos()));
    }

    void generarJSON() {
        std::ostringstream ss;
        ss << "{";
        for (size_t i = 0; i < etiquetas_datos.size(); ++i) {
            ss << " \"" << etiquetas_datos[i].first << "\" : " << etiquetas_datos[i].second;
            if (i != etiquetas_datos.size() - 1) ss << ",";
            ss << "\n ";
        }
        ss << "\b}";
        std::cout << ss.str() << std::endl;
    }
};

int main() {
    Clase1<double> cosas_1;
    cosas_1.agregarCosa(1.3);
    cosas_1.agregarCosa(2.1);
    cosas_1.agregarCosa(3.2);

    Clase1<std::string> cosas_2;
    cosas_2.agregarCosa("Hola");
    cosas_2.agregarCosa("Mundo");

    Clase1<std::vector<int>> cosas_3;
    cosas_3.agregarCosa({1, 2});
    cosas_3.agregarCosa({3, 4});

    Clase2 etiquetas;
    etiquetas.agregarEtiquetas("vec_doubles", cosas_1);
    etiquetas.agregarEtiquetas("palabras", cosas_2);
    etiquetas.agregarEtiquetas("listas", cosas_3);

    etiquetas.generarJSON();
    return 0;
}
