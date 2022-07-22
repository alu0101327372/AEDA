#include "Menu.cpp"

int accion;

int main() {
    std::cout << "--------------\n";
    std::cout << "| Práctica 7 |\n";
    std::cout << "--------------\n";

    // Tipo de Acción
    std::cout << "Mostrar Traza: 1\tMostrar Vector Ordenado: 2\n";
    std::cout << "Tipo de Acción:\n";
    std::cin >> accion;

    switch (accion) {
        case 1:
            std::cout << "---------\n";
            std::cout << "| Traza |\n";
            std::cout << "---------\n";
            Menu();
            break;

        case 2:
            std::cout << "--------------------\n";
            std::cout << "| Vector Ordenando |\n";
            std::cout << "--------------------\n";
            Menu();
        
        default:
            break;
    }
}