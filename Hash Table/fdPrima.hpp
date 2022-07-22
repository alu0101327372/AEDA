#ifndef FDPRIMA_HPP
#define FDPRIMA_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "FuncionDispersion.hpp"

template<class Clave>
class fdPrima : public FuncionDispersion<Clave> {
    public:
        fdPrima(const unsigned n) : nDatos(n){} unsigned operator()(const Clave& k) const {
            srand(time(NULL));
            int x = rand() % nDatos;
            return (1 + x) % (nDatos - 1);
        }
        
    private:
        unsigned nDatos;
};

#endif // FDPRIMA_HPP