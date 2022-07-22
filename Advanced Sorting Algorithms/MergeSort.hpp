#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"

extern int accion;

namespace MergeSort {
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
    mezcla(std::vector<Clave>& sec, int ini, Clave cen, int fin) {
        int i = ini;
        int j = cen + 1;
        int k = fin;
        std::vector<Clave> aux;

        while (i <= cen && j <= fin) {
            if (sec[i] < sec[j]) {
                aux[j] = sec[i];
                i++;
            }

            else {
                aux[k] = sec[j];
                j++;
            }
            k++;
        }

        if (i > cen) {
            while (j <= fin) {
                aux[k] = sec[j];
                j++;
                k++;
            }
        }

        else {
            while (i <= cen) {
                aux[k] = sec[i];
                i++;
                k++;
            }
        }

        for (int x = ini; x <= fin; x++)
            sec[x] = aux[x];
    }
    


    // Algoritmo de Insercion
    template<class Clave> 
    void
    MSort(std::vector<Clave>& sec, int ini, int fin) {
        if (ini < fin) {
            Clave cen = (ini + fin) / 2;
            MSort(sec, ini, cen);
            MSort(sec, cen + 1, fin);
            mezcla(sec, ini, cen, fin);
        }
    }



    template<class Clave> 
    std::vector<Clave>
    MergeSort(std::vector<Clave>& sec, int n) {
        int ini = 0; 
        int fin = n - 1;
        MSort(sec, ini, fin);

        return sec;
    }
}

#endif // HEAPSORT_HPP