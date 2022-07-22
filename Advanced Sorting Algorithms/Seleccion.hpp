#ifndef SELECCION_HPP
#define SELECCION_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"

extern int accion;

namespace Seleccion {
    template<class Clave>
    void 
    print(std::vector<Clave>& sec, int x, int y) {
        // (pos: i + secuencia)
      if(x != -2) {
        std::cout << "i = " << x << " ";
        for(int i = 0; i < sec.size(); i++) {
          if(i < x)
            std::cout << BLUE;
          else if(i == x)
            std::cout << RED;
          else
            std::cout << WHITE;

          std::cout << " " << sec[i] << "  ";
          std::cout << WHITE;
        }
      }

      // (pos: j)
      if(y != -2)
        std::cout << "j = " << y << "\n";
    }
    


    // Algoritmo de Insercion
    template<class Clave> 
    std::vector<Clave>
    Seleccion(std::vector<Clave>& sec, int n) {
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            Clave aux;
            for (int j = i + 1; j < n; j++) {
                if (sec[j] < sec[min])
                    min = j;
            }
            aux = sec[min];
            sec[min] = sec[i];
            sec[i] = aux;
        }
        return sec;
    }
}

#endif // SELECCION_HPP