#ifndef FEDOBLEDISPERSION_HPP
#define FEDOBLEDISPERSION_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "FuncionExploracion.hpp"
#include "FuncionDispersion.hpp"
#include "fdPrima.hpp"

template<class Clave>
class feDobleDispersion : public FuncionExploracion<Clave> {
    public:
        feDobleDispersion(FuncionDispersion<Clave>*&, unsigned);
        unsigned operator()(const Clave& k, unsigned i) const {
            return i * (*fd2_)(k);
        }

    private:
        FuncionDispersion<Clave>* fd2_;
};



template<class Clave>
feDobleDispersion<Clave>::feDobleDispersion(FuncionDispersion<Clave>*& fd, unsigned n) : fd2_(fd) {
    fd2_ = new fdPrima<Clave>(n);
}

#endif // FEDOBLEDISPERSION_HPP