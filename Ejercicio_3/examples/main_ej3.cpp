#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <type_traits>

#include "Clase_1.h"
#include "Clase_2.h"

/*
La clase Clase1<T> permite almacenar una colección de objetos del tipo T y convertirlos 
en una cadena de texto con formato específico según el tipo (double, string o vector<int>). 
Para esto utiliza plantillas y una evaluación en tiempo de compilación con `if constexpr` 
para personalizar la forma en que se genera la representación textual. La clase Clase2 mantiene 
pares de etiquetas y datos, y se encarga de construir una cadena JSON válida con todas las etiquetas y sus respectivos datos. 
*/

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
