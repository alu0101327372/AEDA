#ifndef FDMODULO_HPP
#define FDMODULO_HPP

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
class fdModulo : public FuncionDispersion<Clave> {
    public:
        fdModulo(const unsigned n) : nDatos(n){} unsigned operator()(const Clave& k) const {
            return k % nDatos;
        }
        
    private:
        unsigned nDatos;
};

#endif // FDMODULO_HPP