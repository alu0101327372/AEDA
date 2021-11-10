#ifndef AB_HPP
#define AB_HPP

/** 
 * University of La Laguna
 * Arbol Binario de Búsqueda
 * Advanced Data Structures and Algorithms
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include <queue>
#include "nodoAVL.hpp"


template<class Clave>
class AB {
    public:
        AB(); // Constructor
        ~AB(); // Destructor

        nodoAVL<Clave>*& get_raiz();
        void Podar(nodoAVL<Clave>*&);
        bool esVacio(nodoAVL<Clave>*);
        bool esHoja(nodoAVL<Clave>*);

        void preOrden(nodoAVL<Clave>*);
        void inOrden(nodoAVL<Clave>*);
        void postOrden(nodoAVL<Clave>*);

        const int Tam(); // Tamaño
        const int Alt(); // Altura
        const bool Equilibrado(); // Arbol Binario Equilibrado

        void Mostrar(); //  Imprimir el árbol según su estructura.

    protected:
        nodoAVL<Clave>* raiz_;

    private:
        const int TamRama(nodoAVL<Clave>*&);
        const int AltN(nodoAVL<Clave>*);
        const bool EquilibrioRama(nodoAVL<Clave>*);
};



template<class Clave>
AB<Clave>::AB() : raiz_(NULL) {}



template<class Clave>
AB<Clave>::~AB() {
    Podar(raiz_);
}



template<class Clave>
const int
AB<Clave>::TamRama(nodoAVL<Clave>*& nodo) {
    if (nodo == NULL) return 0;
    return (1 + TamRama(nodo->get_izq()) + 
                TamRama(nodo->get_der()));
}



template<class Clave>
const int
AB<Clave>::AltN(nodoAVL<Clave>* nodo) {
    if (nodo == NULL) return 0;
    int alt_i = AltN(nodo->get_izq());
    int alt_d = AltN(nodo->get_der());
    if (alt_d > alt_i)
        return ++alt_d;
    else   
        return ++alt_i;
}



template<class Clave>
const bool
AB<Clave>::EquilibrioRama(nodoAVL<Clave>* nodo) {
    if (nodo == NULL) return true;
    int eq = TamRama(nodo->get_izq() - TamRama(nodo->get_der()));
    switch (eq) {
        case -1:
        case 0:
        case 1:
            return EquilibrioRama(nodo->get_izq() && EquilibrioRama(nodo->get_der()));

        default: return false;
    }
}



template<class Clave>
nodoAVL<Clave>*&
AB<Clave>::get_raiz() {
    return raiz_;
}



template<class Clave>
void
AB<Clave>::Podar(nodoAVL<Clave>*& nodo) {
    if (nodo == NULL)
        return;
    Podar(nodo->get_izq()); //Podar subarbol izquierdo
    Podar(nodo->get_der()); //Podar subarbol derecho
    delete nodo;
    nodo = nullptr;
}



template<class Clave>
bool
AB<Clave>::esVacio(nodoAVL<Clave>* nodo) {
    return nodo = NULL; // Esta vacio si no hay nodos
}



template<class Clave>
bool
AB<Clave>::esHoja(nodoAVL<Clave>* nodo) {
    return !nodo->get_izq() && !nodo->get_der(); // Es Hoja si no tiene subarboles
}



template<class Clave>
void
AB<Clave>::preOrden(nodoAVL<Clave>* nodo) {
    if (nodo == NULL) return;
    std::cout << nodo->get_dato();
    preOrden(nodo->get_izq());
    preOrden(nodo->get_der());
}



template<class Clave>
void
AB<Clave>::inOrden(nodoAVL<Clave>* nodo) {
    if (nodo == NULL) return;
    inOrden(nodo->get_izq());
    std::cout << nodo->get_dato();
    inOrden(nodo->get_der());
}



template<class Clave>
void
AB<Clave>::postOrden(nodoAVL<Clave>* nodo) {
    if (nodo == NULL) return;
    inOrden(nodo->get_izq());
    inOrden(nodo->get_der());
    std::cout << nodo->get_dato();
}



template<class Clave>
const int
AB<Clave>::Tam() {
    return TamRama(raiz_);
}



template<class Clave>
const int
AB<Clave>::Alt() {
    return AltN(raiz_);
}



template<class Clave>
const bool
AB<Clave>::Equilibrado() {
    return EquilibrioRama(raiz_);
}



template<class Clave>
void
AB<Clave>::Mostrar() {
    // Recorrido por niveles
    std::queue<std::pair<nodoAVL<Clave>*,int> > Q;
    nodoAVL<Clave>* nodo;
    int nivel, Nivel_actual = 0;
    Q.push(std::make_pair(raiz_, 0));
    std::cout << "Nivel 0: ";

    while (!Q.empty()) {
        // Guardamos el primer valor de la cola
        std::pair<nodoAVL<Clave>*,int> p;
        p = Q.front();
        nodo = p.first;
        nivel = p.second;

        // Quitamos la pareja(nodo, nivel) de la Cola
        Q.pop();

        if (nivel > Nivel_actual) {
            Nivel_actual = nivel; // Incremento de nivel
            std::cout << "\nNivel " << Nivel_actual << ": ";
        }

        // Mostramos el valor del nodo
        nodo->print();
        if (nodo != NULL) {
            Q.push(std::make_pair(nodo->get_izq(), nivel + 1));
            Q.push(std::make_pair(nodo->get_der(), nivel + 1));
        }
    }
    std::cout << "\n";
}

#endif // AB_HPP