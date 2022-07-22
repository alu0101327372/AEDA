#ifndef FUNCIONEXPLORACION_HPP
#define FUNCIONEXPLORACION_HPP

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
class FuncionExploracion {
    public:
        virtual unsigned operator()(const Clave& k, unsigned i) const = 0;
};

#endif // FUNCIONEXPLORACION_HPP