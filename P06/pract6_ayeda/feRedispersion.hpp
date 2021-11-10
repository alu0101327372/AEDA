#ifndef FEREDISPERSION_HPP
#define FEREDISPERSION_HPP

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
#include "fdModulo.hpp"
#include "fdPseudoaleatoria.hpp"

template<class Clave>
class feRedispersion : public FuncionExploracion<Clave> {
    public:
        feRedispersion(FuncionDispersion<Clave>*&, unsigned);
        unsigned operator()(const Clave& k, unsigned i) const {
            srand(i + k);
            switch (rand() % 2) {
                case 0:
                    fd3_ = static_cast<fdModulo<Clave>* >(fd3_);
                    std::cout << "0-";
                    break;

                case 1:
                    fd3_ = static_cast<fdPseudoaleatoria<Clave>* >(fd3_);
                    std::cout << "1-";
                    break;
                
                default:
                    break;
            }
            return ((*fd3_)(k) + i) % nDatos;
        }
    
    private:
        FuncionDispersion<Clave>* fd3_;
        unsigned nDatos;
};



template<class Clave>
feRedispersion<Clave>::feRedispersion(FuncionDispersion<Clave>*& fd, unsigned n) : fd3_(fd), nDatos(n) {
  srand(time(NULL));
  switch (rand() % 2) {
    case 0: 
        fd3_ = new fdModulo<Clave>(nDatos);
        break;

    case 1: 
        fd3_ = new fdPseudoaleatoria<Clave>(nDatos);
        break;
  }
}

#endif // FEREDISPERSION_HPP