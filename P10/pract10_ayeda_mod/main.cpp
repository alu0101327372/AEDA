#include "ABB.hpp"

/** 
 * University of La Laguna
 * Arbol Binario de Búsqueda
 * Advanced Data Structures and Algorithms
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */


int main() {
    std::cout << "--------------\n";
    std::cout << "|  Practica 10 |\n";
    std::cout << "--------------\n";

    // Creamos el arbol vacio
    ABB<int> ABB;
    ABB.Mostrar();

    int op;
    std::cout << "\n0: Salir\t1: Insertar\t2: Buscar\t3: Eliminar\t4: Suma\n";
    std::cout << "Opcion: ";
    std::cin >> op;

    while (op != 0) {
        if (op == 1) {
            int dato;
            std::cout << "Introducir Un Valor: ";
            std::cin >> dato;
            ABB.Insertar(dato);
            ABB.Mostrar();
        }

        if (op == 2) {
            int dato;
            std::cout << "Clave a Buscar: " << "\n";
            std::cin >> dato;
            if (ABB.Buscar(dato) == true)
                std::cout << "Encontrado";

            else 
                std::cout << "No encontrado";
        }

        if (op == 3) {
            int dato;
            std::cout << "Introducir Un Valor: ";
            std::cin >> dato;
            ABB.Eliminar(dato);
            ABB.Mostrar();
        }

        if (op == 4)
            std::cout << "La suma es: " << ABB.suma() << std::endl;

        std::cout << "\n0: Salir\t1: Insertar\t2: Buscar\t3: Eliminar\t4: Suma\n";
        std::cout << "Opcion: ";
        std::cin >> op;
    }

    return 0;
}