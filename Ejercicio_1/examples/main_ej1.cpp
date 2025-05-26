#include "SaveFlightData.h"

int main() {
    // Creacion de objetos de datos iniciales.
    Posicion posicion_Inicial(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion_Inicial(101.3f, 5.8f, 6.1f);
    SaveFlightData save_Inicial(posicion_Inicial, presion_Inicial);

    // Serialization de los datos.
    std::ofstream archivoSalida("datosVuelo.bin", std::ios::binary);
    if (!archivoSalida) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return 1;
    }

    if(archivoSalida.is_open()) {
        save_Inicial.serializar(archivoSalida);
        archivoSalida.close();
    } 

    // Deserialization de los datos.
    // Creacion de objetos vacios para la deserializacion.
    Posicion posicion_des(0.0f, 0.0f, 0.0f, 0.0f);
    Presion presion_des(0.0f, 0.0f, 0.0f);
    SaveFlightData save_des(posicion_des, presion_des);

    // Deserializacion de los datos.
    std::ifstream archivoEntrada("datosVuelo.bin", std::ios::binary);
    if (!archivoEntrada) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return 1;
    }
    if(archivoEntrada.is_open()) {
        save_des.deserializar(archivoEntrada);
        archivoEntrada.close();
    }

    // Imprimir los datos deserializados.
    std::cout << "==================================" << std::endl;
    std::cout << "Deserializacion Completada. Datos:" << std::endl;
    save_des.imprimir();
    std::cout << "Fin del programa.\n" << std::endl;

    return 0;  
}