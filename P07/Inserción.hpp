#ifndef INSERCION_HPP
#define INSERCION_HPP

#include <iostream>
#include <vector>

#define WHITE   "\e[0m"
#define BLUE	"\e[34m"
#define RED     "\e[31m"

extern int accion;

namespace Insercion {
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
    Insercion(std::vector<Clave> sec, int n) {
        int j;
        Clave aux;

        for (int i = 1; i < n; i++) {
            aux = sec[i];
            if (accion == 1)
                print(sec, i, -2);
            j = i - 1;
            while (j >= 0 && sec[j] > aux) {
                sec[j + 1] = sec[j];
                j--;
            }
            sec[j + 1] = aux;
            if (accion == 1)
                print(sec, -2, j + 1);
        }
        return sec;
    }
}

#endif // INSERCION_HPP