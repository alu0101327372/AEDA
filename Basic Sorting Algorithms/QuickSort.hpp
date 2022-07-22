#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"

extern int accion;

namespace QuickSort {
    template<class Clave>
    void
    print(std::vector<Clave>& sec, int ini, int fin, Clave p) {
        std::cout << "Pivote: " << p << "\t";
        for (int i = 0; i < sec.size(); i++) {
            if(i == ini)
                std::cout << BLUE << sec[i] << " ";
            else if(i == fin)
                std::cout << RED << sec[i] << " ";
            else
                std::cout << WHITE << sec[i] << " ";
            std::cout << WHITE;
        }
        std::cout << "\n";
    }



    // Algoritmo de QuickSort
    template<class Clave> 
    void
    OrdenacionRapida(std::vector<Clave>& sec, int ini, int fin) {
        int i = ini; int j = fin;
        Clave p = sec[(i + j) / 2];
        if (accion == 1)
            print(sec, i, j, p);

        while (i <= j) {
            while (sec[i] < p) {
                if (accion == 1)
                    print(sec, i, j, p);
                i++;
            }

            while (sec[j] > p) {
                if (accion == 1)
                    print(sec, i, j, p);
                j--;          
            }

            if (i <= j) {
                std::swap(sec[i], sec[j]);
                i++;
                j--;
            }
        }
        if (ini < j)
            OrdenacionRapida(sec, ini, j);
        if (i < fin)
            OrdenacionRapida(sec, i, fin);
    }



    template<class Clave>
    std::vector<Clave>
    QuickSort(std::vector<Clave>& sec, int n) {
        int ini = 0; int fin = n - 1;
        OrdenacionRapida(sec, ini, fin);

        //Retornamos la secuencia ordenada
        return sec;
    }
}



#endif // QUICKSORT_HPP