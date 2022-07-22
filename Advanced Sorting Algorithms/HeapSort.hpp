#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"

extern int accion;

namespace HeapSort {
    template<class Clave>
    void 
    print(std::vector<Clave>& sec, int n, int h1, int h2, int h) {
      for(int i = 0; i < n; i++) {
        if(i == h)
          std::cout << "\e[34m" << sec[i] << " ";
        else if(i == h1)
          std::cout << "\e[31m" << sec[i] << " ";
        else if(i == h2)
          std::cout << "\e[32m" << sec[i] << " ";
        else
          std::cout << "\e[0m" << sec[i] << " ";
        std::cout << "\e[0m";
      }
      std::cout << "\n";
    }



    template<class Clave>
    void 
    baja(std::vector<Clave>& sec, int n, int i) {
        int h = i;
        int h1 = 2 * i + 1;
        int h2 = 2 * i + 1;

        if (accion == 1)
            print(sec, n, h1, h2, h);

        if (h1 < n && sec[h1] > sec[h])
            h = h1;

        if (h2 < n && sec[h2] > sec[h])
            h = h2;

        if (h != i) {
            std::swap(sec[i], sec[h]);
            baja(sec, n, h);
        }
    }
    


    // Algoritmo de Insercion
    template<class Clave> 
    std::vector<Clave>
    HeapSort(std::vector<Clave>& sec, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            baja(sec, n, i);

        for (int i = n - 1; i >= 0; i--) {
            std::swap(sec[0], sec[i]);
            baja(sec, 0, i);
        }

        return sec;
    }
}

#endif // HEAPSORT_HPP