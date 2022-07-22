#ifndef FECUADRATICA_HPP
#define FECUADRATICA_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "FuncionExploracion.hpp"

template<class Clave>
class feCuadractica : public FuncionExploracion<Clave> {
    public:
        unsigned operator()(const Clave& k, unsigned i) const {
            return i * i;
        }
};

#endif // FECUADRATICA_HPP