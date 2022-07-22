#include "AB.hpp"


int main() {
    std::cout << "--------------\n";
    std::cout << "|  Practica 9 |\n";
    std::cout << "--------------\n";

    // Creamos el arbol vacio
    AB<int> AB;
    AB.Mostrar();

    int op;
    std::cout << "\n0: Salir\t1: Insertar\t2: Buscar\n";
    std::cout << "Opcion: ";
    std::cin >> op;

    while (op != 0) {
        if (op == 1) {
            int dato;
            std::cout << "Introducir Un Valor: ";
            std::cin >> dato;
            AB.Insertar(dato);
            AB.Mostrar();
        }

        if (op == 2) {
            int dato;
            std::cout << "Clave a Buscar: " << "\n";
            std::cin >> dato;
            if (AB.Buscar(dato) == true)
                std::cout << "Encontrado";

            else 
                std::cout << "No encontrado";
        }

        std::cout << "\n0: Salir\t1: Insertar\t2: Buscar\n";
        std::cout << "Opcion: ";
        std::cin >> op;
    }

    return 0;
}