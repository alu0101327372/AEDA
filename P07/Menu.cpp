#include "Inserción.hpp"
#include "QuickSort.hpp"
#include "ShellSort.hpp"



void Menu() {
    // Solicitar Tamaño
    int n;
    std::cout << "Tamaño de la secuencia a ordenar:\n";
    std::cin >> n;
    std::cout << std::endl;

    // Tipo de Vector
    int vector;
    std::cout << "Aleatoria: 1\tManual: 2\n";
    std::cout << "Tipo de Acción:\n";
    std::cin >> vector;
    std::cout << std::endl;

    // Generar una secuencia de tamaño N 
    std::vector<int> sec(n);

    switch (vector) {
        case 1:
            srand(time(NULL));
            for (int i = 0; i < sec.size(); i++) 
                sec[i] = 1 + int(rand()) % 1000;

            std::cout << std::endl;
            break;

        case 2:
            std::cout << "Introduzca los valores del vector:\n";
            for (int i = 0; i < sec.size(); i++) {
                int valor;
                std::cin >> valor;
                sec[i] = valor;
            }
            std::cout << std::endl;
        
        default:
            break;
    }

    //Mostrar Vector Original
    std::cout << "Vector Original\n";
    for (auto d : sec)
        std::cout << d << "  ";
    std::cout << "\n";

    // Solicitar Algoritmo de Ordenación
    int tipo;
    std::cout << std::endl;
    std::cout << "Inserción: 1\tQuickSort: 2\tShellSort: 3\n";
    std::cout << "Tipo de Algoritmo:\n";
    std::cin >> tipo;
    std::cout << std::endl;

    // Creamos el vector en donde va a estar guardado el vector ordenado
    std::vector<int> sec_ordenada;

    switch (tipo) {
        case 1:
            sec_ordenada = Insercion::Insercion<int>(sec, n);
            break;

        case 2:
            sec_ordenada = QuickSort::QuickSort<int>(sec, n);
            break;

        case 3:
            sec_ordenada = ShellSort::ShellSort<int>(sec, n);
            break;
        
        default:
            break;
    }

    std::cout << std::endl;
    std::cout <<"Vector Ordenado\n";
    for (auto d : sec_ordenada)
        std::cout << d << "  ";
    std::cout << "\n"; 
}