#ifndef nodoB_HPP
#define nodoB_HPP


#include <iostream>


template<class Clave>
class nodoB {
    public:
        nodoB(Clave, nodoB* izq = NULL, nodoB* der = NULL); // Constructor
        ~nodoB();

        nodoB<Clave>*& get_izq();
        nodoB<Clave>*& get_der();
        Clave& get_dato();
        void print() const; // Imprimir los nodos del árbol según su estructura.

    private:
        Clave dato_; // Cualquier tipo de valor a almacenar
        nodoB* izq_;
        nodoB* der_;
};



template<class Clave>
nodoB<Clave>::nodoB(Clave dato, nodoB* izq, nodoB* der) :
dato_(dato),
izq_(izq),
der_(der) 
{}



template<class Clave>
nodoB<Clave>::~nodoB() {}



template<class Clave>
nodoB<Clave>*&
nodoB<Clave>::get_izq() {
    return izq_;
}



template<class Clave>
nodoB<Clave>*&
nodoB<Clave>::get_der() {
    return der_;
}



template<class Clave>
Clave&
nodoB<Clave>::get_dato() {
    return dato_;
}



template<class Clave>
void
nodoB<Clave>::print() const {
    if (this != nullptr)
        std::cout << "[" << dato_ << "]";

    else 
        std::cout << "[.]";
}


#endif // nodoB_HPP