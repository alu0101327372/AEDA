#ifndef FDPSEUDOALEATORIA_HPP
#define FDPSEUDOALEATORIA_HPP

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
class fdPseudoaleatoria : public FuncionDispersion<Clave> {
    public:
        fdPseudoaleatoria(const unsigned n) : nDatos(n){} unsigned operator()(const Clave& k) const {
            srand(k);
            return rand() % nDatos;
        }
        
    private:
        unsigned nDatos;
};

#endif // FDPSEUDOALEATORIA_HPP