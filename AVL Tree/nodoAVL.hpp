#ifndef nodoAVL_HPP
#define nodoAVL_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Hormiga de Langton
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */


#include <iostream>


template<class Clave>
class nodoAVL {
    public:
        nodoAVL(Clave, nodoAVL* izq = NULL, nodoAVL* der = NULL, int bal = 0); // Constructor
        ~nodoAVL();

        nodoAVL<Clave>*& get_izq();
        nodoAVL<Clave>*& get_der();
        Clave& get_dato();
        int& get_bal();

        void set_bal(Clave);
        void set_dato(Clave);

        void print() const; // Imprimir los nodos del árbol según su estructura.

    private:
        Clave dato_; // Cualquier tipo de valor a almacenar
        nodoAVL* izq_;
        nodoAVL* der_;
        int bal_;
};



template<class Clave>
nodoAVL<Clave>::nodoAVL(Clave dato, nodoAVL* izq, nodoAVL* der, int bal) :
dato_(dato),
izq_(izq),
der_(der),
bal_(bal)
{}



template<class Clave>
nodoAVL<Clave>::~nodoAVL() {}



template<class Clave>
nodoAVL<Clave>*&
nodoAVL<Clave>::get_izq() {
    return izq_;
}



template<class Clave>
nodoAVL<Clave>*&
nodoAVL<Clave>::get_der() {
    return der_;
}



template<class Clave>
Clave&
nodoAVL<Clave>::get_dato() {
    return dato_;
}



template<class Clave>
void
nodoAVL<Clave>::set_dato(Clave dato) {
    dato_ = dato;
}



template<class Clave>
int&
nodoAVL<Clave>::get_bal() {
    return bal_;
}



template<class Clave>
void
nodoAVL<Clave>::set_bal(Clave bal) {
    bal_ = bal;
}



template<class Clave>
void
nodoAVL<Clave>::print() const {
    if (this != nullptr)
        std::cout << "[" << dato_ << "]";

    else 
        std::cout << "[.]";
}

#endif // nodoAVL_HPP