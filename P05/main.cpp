/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "Lista.hpp"

int main() {
    //Parametros para crear la tabla Hash
    int nCeldas; // Tamaño de la Tabla Hash
    int tipoFDispersion;   // Tipo de Funcion de Dispersion
    int tipoAccion;  // Tipo de Acción sobre la Tabla Hash

    //Solicitar los parametros para crear la tabla Hash
    std::cout << "Introducir Numero de Celdas: ";
    std::cin >> nCeldas;

    std::cout << "Elegir una Funcion de Dispersion\n";
    std::cout << "Modulo: 0\tPseudoaleatoria: 1\n";
    std::cout << "Tipo: ";
    std::cin >> tipoFDispersion;

    Lista<int> lista(nCeldas, tipoFDispersion);

    std::cout << "Elegir una Acción sobre la Tabla\n";
    std::cout << "Fin: 0\tInsertar: 1\tBuscar: 2\n";
    std::cin >> tipoAccion;

    while (tipoAccion != 0) {
        if (tipoAccion == 1) {
            int valor;
            std::cout << "Introducir Un Valor: ";
            std::cin >> valor;
            lista.Insertar(valor);
            lista.Mostrar();
        }

        if (tipoAccion == 2) {
            int valor2;
            std::cout << "Introducir Un Valor: ";
            std::cin >> valor2;
            lista.Buscar(valor2);
            lista.Mostrar();
        }
        std::cout << std::endl;
        std::cout << "Elegir una Acción sobre la Tabla\n";
        std::cout << "Fin: 0\tInsertar: 1\tBuscar: 2\n";
        std::cin >> tipoAccion;
    }
}

