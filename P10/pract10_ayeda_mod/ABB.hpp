#ifndef ABB_HPP
#define ABB_HPP

#include "AB.hpp"

/** 
 * University of La Laguna
 * Arbol Binario de Búsqueda
 * Advanced Data Structures and Algorithms
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */


template<class Clave>
class ABB : public AB<Clave> {
    public:
        ABB();
        ~ABB();

        bool Buscar(Clave&); // Buscar un valor en el arbol
        void Insertar(const Clave&); // Inserción en el arbol
        void Eliminar(const Clave&); // Eliminar un nodo del arbol

        void recorrer(nodoB<Clave>*&, int&);
        int suma();

    private:
        bool BuscarRama(nodoB<Clave>*, const Clave&);
        void InsertarRama(nodoB<Clave>*&, const Clave&);
        void EliminarRama(nodoB<Clave>*&, const Clave&);
        void Sustituye(nodoB<Clave>*&, nodoB<Clave>*&);
};



template<class Clave>
ABB<Clave>::ABB() : AB<Clave>() {}



template<class Clave>
ABB<Clave>::~ABB() {}



template<class Clave>
bool
ABB<Clave>::Buscar(Clave& X) {
    return BuscarRama(this->get_raiz(), X);
}



template<class Clave>
bool
ABB<Clave>::BuscarRama(nodoB<Clave>* nodo, const Clave& X) {
    if (nodo == NULL) return false;
    if (X == nodo->get_dato()) return true;

    bool clave1 = BuscarRama(nodo->get_izq(), X);
    if (clave1 == true)
        return true;

    return BuscarRama(nodo->get_der(), X);
}



template<class Clave>
void
ABB<Clave>::Insertar(const Clave& X) {
    InsertarRama(this->get_raiz(), X);
}



template<class Clave>
void
ABB<Clave>::InsertarRama(nodoB<Clave>*& nodo, const Clave& X) {
    if (nodo == NULL) 
        nodo = new nodoB<Clave>(X);

    else if (X < nodo->get_dato())
        InsertarRama(nodo->get_izq(), X);

    else
        InsertarRama(nodo->get_der(), X); 
}



template<class Clave>
void
ABB<Clave>::Eliminar(const Clave& X) {
    EliminarRama(this->get_raiz(), X);
}



template<class Clave>
void
ABB<Clave>::EliminarRama(nodoB<Clave>*& nodo, const Clave& X) {
    if (nodo == NULL) return;
    if (X < nodo->get_dato())
        EliminarRama(nodo->get_izq(), X);
    else if (X > nodo->get_dato())
        EliminarRama(nodo->get_der(), X);
    else {
        nodoB<Clave>* Eliminado= nodo;
        if (nodo->get_der() == NULL)
            nodo = nodo->get_izq();
        else if (nodo->get_izq() == NULL)
            nodo = nodo->get_der();
        else 
            Sustituye(Eliminado, nodo->get_izq());

        delete Eliminado;
    }
}



template<class Clave>
void
ABB<Clave>::Sustituye(nodoB<Clave>*& Eliminado, nodoB<Clave>*& Sust) {
    if (Sust->get_der() != NULL)
        Sustituye(Eliminado, Sust->get_der());
    else {
        Eliminado->get_dato() = Sust->get_dato();
        Eliminado = Sust;
        Sust = Sust->get_izq();
    }
}



template<class Clave>
void
ABB<Clave>::recorrer(nodoB<Clave>*& nodo, int& suma) {
    if (nodo == NULL) return;
    suma += nodo->get_dato();
    recorrer(nodo->get_izq(), suma);
    recorrer(nodo->get_der(), suma);
}




template<class Clave>
int
ABB<Clave>::suma() {
    int suma = 0;
    if (this->get_raiz() == NULL) return 0;
    else {
        recorrer(this->get_raiz(), suma);
    }

    return suma;
}


#endif // ABB_HPP
