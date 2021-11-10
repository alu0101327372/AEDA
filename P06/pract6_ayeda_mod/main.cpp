/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "TablaHash.hpp"
#include "Producto.hpp"

int main() {
    //Parametros para crear la tabla Hash
    int nCeldas; // Tamaño de la Tabla Hash
    int nClaves; // Numero de Claves
    int tipoFDispersion;   // Tipo de Funcion de Dispersion
    int tipoFExploración;  // Tipo de Funcion de Exploracion
    int tipoAccion;  // Tipo de Acción sobre la Tabla Hash

    //Solicitar los parametros para crear la tabla Hash
    std::cout << "Introducir Numero de Celdas: ";
    std::cin >> nCeldas;
    std::cout << "Introducir NUmero de Claves: ";
    std::cin >> nClaves;

    std::cout << "Elegir una Funcion de Dispersion\n";
    std::cout << "Modulo: 0\tPseudoaleatoria: 1\n";
    std::cout << "Tipo: ";
    std::cin >> tipoFDispersion;

    std::cout << "Elegir una Funcion de Exploración\n";
    std::cout << "Lineal: 0\tCuadráctica: 1\tDoble Dispersión: 2\tRedispersión: 3\n";
    std::cout << "Tipo: ";
    std::cin >> tipoFExploración;

    TablaHash<Producto> tabla(nCeldas, nClaves, tipoFDispersion, tipoFExploración);

    std::cout << "Elegir una Acción sobre la Tabla\n";
    std::cout << "Fin: 0\tInsertar: 1\tBuscar: 2\n";
    std::cin >> tipoAccion;

    while (tipoAccion != 0) {
        if (tipoAccion == 1) {
            int valor, precio;
            std::string nombre;
            std::cout << "Introducir Un Valor: ";
            std::cin >> valor;
            std::cout << "Introducir Un Nombre: ";
            std::cin >> nombre;
            std::cout << "Introducir Un Precio: ";
            std::cin >> precio;
            Producto prod(valor, nombre, precio);
            tabla.Insertar(prod);
            tabla.Mostrar();
        }

        if (tipoAccion == 2) {
            int valor2;
            std::cout << "Introducir Un Valor: ";
            std::cin >> valor2;
            Producto prod2(valor2);
            tabla.Buscar(prod2);
            tabla.Mostrar();
        }
        std::cout << std::endl;
        std::cout << "Elegir una Acción sobre la Tabla\n";
        std::cout << "Fin: 0\tInsertar: 1\tBuscar: 2\n";
        std::cin >> tipoAccion;
    }
}

