#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"


extern int accion;

namespace ShellSort {
    template<class Clave>
    void
    print(std::vector<Clave>& sec, int n, int j, int del) {
        for (int i = 0; i < n; i++) {
            if (i == j)
                std::cout << BLUE << sec[i] << " ";
            else if (i == j - del)
                std::cout << RED << sec[i] << " ";
            else 
                std::cout << WHITE << sec[i] << " ";
            std::cout << WHITE;
        }
        std::cout << "\n";
    }



    template<class Clave> 
    void
    DeltaSort(std::vector<Clave>& sec, int n, int del) {
        for (int i = del; i < n; i++) {
            Clave x = sec[i];
            int j = i;
            if (accion == 1)
                print(sec, n, j, del);
            
            while ((j >= del) && (x < sec[j - del])) {
                sec[j] = sec[j - del];
                j = j - del;
            }
            sec[j] = x;
        }
    }



    // Algoritmo de ShellShort
    template<class Clave> 
    std::vector<Clave>
    ShellSort(std::vector<Clave> sec, int n) {
        double a;
        std::cout << "Introduce la constante de reducción alfa:" << std::endl;
        std::cin >> a;
        std::cout << std::endl;

        int del = n * a;
        while (del >= 1) {
            del = del * a;
            DeltaSort(sec, n, del);
        }
        return sec;
    }
}

#endif // SHELLSORT_HPP