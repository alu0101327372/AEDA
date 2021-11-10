#ifndef FUNCIONDISPERSION_HPP
#define FUNCIONDISPERSION_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include <iostream>

template<class Clave> 
class FuncionDispersion {
    public:
        virtual unsigned operator()(const Clave& k) const = 0;
};

#endif // FUNCIONDISPERSION_HPP