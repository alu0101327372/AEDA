#ifndef AVL_HPP
#define AVL_HPP

/** 
 * University of La Laguna
 * Arbol Binario de Búsqueda
 * Advanced Data Structures and Algorithms
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */


#include <iostream>
#include "nodoAVL.hpp"
#include "ABB.hpp"


template<class Clave>
class AVL : public ABB<Clave> {
    public:
        AVL();
        ~AVL();

        bool Busqueda(Clave&);
        void Insertar(const Clave&);
        void Eliminar(const Clave&);
        void MostrarTraza();

    private:
        void rotacionII(nodoAVL<Clave>*&);
        void rotacionDD(nodoAVL<Clave>*&);
        void rotacionID(nodoAVL<Clave>*&);
        void rotacionDI(nodoAVL<Clave>*&);

        void Inserta_bal(nodoAVL<Clave>*&, nodoAVL<Clave>*, bool&);
        void Insert_re_balancea_izq(nodoAVL<Clave>*&, bool&);
        void Insert_re_balancea_dcha(nodoAVL<Clave>*&, bool&);

        void Elimina_rama(nodoAVL<Clave>*&, Clave, bool&);
        void Eliminar_re_balancea_izq(nodoAVL<Clave>*&, bool&);
        void Eliminar_re_balancea_dcha(nodoAVL<Clave>*&, bool&);

        void Sustituye_avl(nodoAVL<Clave>*&, nodoAVL<Clave>*&, bool&);
};



template<class Clave>
AVL<Clave>::AVL() : ABB<Clave>() {}



template<class Clave>
AVL<Clave>::~AVL() {}



template<class Clave>
bool
AVL<Clave>::Busqueda(Clave& X) {
    return Buscar(X);
}



template<class Clave>
void
AVL<Clave>::Insertar(const Clave& X) {
    nodoAVL<Clave>* nuevo = new nodoAVL<Clave>(X);
    bool crece = false;
    Inserta_bal(this->get_raiz(), nuevo, crece);
}



template<class Clave>
void
AVL<Clave>::Inserta_bal(nodoAVL<Clave>*& nodo, nodoAVL<Clave>* nuevo, bool& crece) {
    if (nodo == NULL) {
        nodo = nuevo;
        crece = true;
    }
    else if (nuevo->get_dato() < nodo->get_dato()) {
        Inserta_bal(nodo->get_izq(), nuevo, crece);
        if (crece) Insert_re_balancea_izq(nodo, crece);
    }
    else {
        Inserta_bal(nodo->get_der(), nuevo, crece);
        if (crece) Insert_re_balancea_dcha(nodo, crece);
    }
}



template<class Clave>
void
AVL<Clave>::Insert_re_balancea_izq(nodoAVL<Clave>*& nodo, bool& crece) {
    nodoAVL<Clave>* nodo1;
  switch (nodo->get_bal()) {
        case -1: 
            nodo->set_bal(0);
            crece = false;
            break;
        case 0:
            nodo->set_bal(1);
            break;
        case 1:
            nodo1 = nodo->get_izq();
            if (nodo->get_bal() == 1)
                rotacionII(nodo);
            else 
                rotacionID(nodo);
            crece = false;
            break;
    }  
}



template<class Clave>
void
AVL<Clave>::Insert_re_balancea_dcha(nodoAVL<Clave>*& nodo, bool& crece) {
    nodoAVL<Clave>* nodo1;
    switch (nodo->get_bal()) {
        case 1: 
            nodo->set_bal(0);
            crece = false;
            break;
        case 0:
            nodo->set_bal(-1);
            break;
        case -1:
            nodo1 = nodo->get_der();
            if (nodo1->get_bal() == -1)
                rotacionDD(nodo);
            else 
                rotacionDI(nodo);
            crece = false;
            break;
    }
}


template<class Clave>
void
AVL<Clave>::Eliminar(const Clave& X) {
    bool decrece = false;
    Elimina_rama(this->get_raiz(), X, decrece);
}



template<class Clave>
void
AVL<Clave>::Elimina_rama(nodoAVL<Clave>*& nodo, Clave X, bool& decrece) {
    if (nodo == NULL) return;
    if (X < nodo->get_dato()) {
        Elimina_rama(nodo->get_izq(), X, decrece);
        if (decrece)
            Eliminar_re_balancea_izq(nodo, decrece);
    }
    else if (X > nodo->get_dato()) {
        Elimina_rama(nodo->get_der(), X, decrece);
        if (decrece)
            Eliminar_re_balancea_dcha(nodo, decrece);
    }
    else {
        nodoAVL<Clave>* Eliminado = nodo;
        if (nodo->get_izq() == NULL) {
            nodo = nodo->get_der();
            decrece = true;
        }
        else if (nodo->get_der() == NULL) {
            nodo = nodo->get_izq();
            decrece = true;
        }
        else {
            Sustituye_avl(Eliminado, nodo->get_izq(), decrece);
            if (decrece)
                Eliminar_re_balancea_izq(nodo, decrece);
        }
        delete Eliminado;
    }
}



template<class Clave>
void
AVL<Clave>::Eliminar_re_balancea_izq(nodoAVL<Clave>*& nodo, bool& decrece) {
    nodoAVL<Clave>* nodo1;
    switch (nodo->get_bal()) {
            case -1:
                nodo1 = nodo->get_der();
                if (nodo1->get_bal() > 0)
                    rotacionDI(nodo);
                else {
                    if (nodo1->get_bal() == 0)
                        decrece = false;
                    rotacionDD(nodo);
                }
                break;
            case 0:
                nodo->set_bal(-1);
                decrece = false;
                break;
            case 1:
                nodo->set_bal(0);
    } 
}



template<class Clave>
void
AVL<Clave>::Eliminar_re_balancea_dcha(nodoAVL<Clave>*& nodo, bool& decrece) {
    nodoAVL<Clave>* nodo1;
    switch (nodo->get_bal()) {
            case 1:
                nodo1 = nodo->get_izq();
                if (nodo1->get_bal() < 0)
                    rotacionID(nodo);
                else {
                    if (nodo1->get_bal() == 0)
                        decrece = false;
                    rotacionII(nodo);
                }
                break;
            case 0:
                nodo->set_bal(1);
                decrece = false;
                break;
            case -1:
                nodo->set_bal(0);
                break;
    } 
}



template<class Clave>
void
AVL<Clave>::Sustituye_avl(nodoAVL<Clave>*& Eliminado, nodoAVL<Clave>*& Sust, bool& decrece) {
    if (Sust->get_der() != NULL) {
        Sustituye_avl(Eliminado, Sust->get_der(), decrece);
        if (decrece)
            Eliminar_re_balancea_dcha(Sust, decrece);
    }
    else {
        Eliminado->set_dato(Sust->get_dato());
        Eliminado = Sust;
        Sust = Sust->get_izq();
        decrece = true;
    }
}



template<class Clave>
void
AVL<Clave>::rotacionII(nodoAVL<Clave>*& nodo) {
    nodoAVL<Clave>* nodo1 = nodo->get_izq();
    nodo->get_izq() = nodo1->get_der();
    nodo1->get_der() = nodo;
    if (nodo1->get_bal() == 1) {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    } 
    else {
        nodo->set_bal(1);
        nodo1->set_bal(-1);
    }
    nodo = nodo1;
}



template<class Clave>
void
AVL<Clave>::rotacionDD(nodoAVL<Clave>*& nodo) {
    nodoAVL<Clave>* nodo1 = nodo->get_der();
    nodo->get_der() = nodo1->get_izq();
    nodo1->get_izq() = nodo ;
    if (nodo1->get_bal() == -1) {
        nodo->set_bal(0);
        nodo1->set_bal(0);
    }
    else {
        nodo->set_bal(-1);
        nodo1->set_bal(1);
    }
    nodo = nodo1; 
}



template<class Clave>
void
AVL<Clave>::rotacionID(nodoAVL<Clave>*& nodo) {
    nodoAVL<Clave>* nodo1 = nodo->get_izq();
    nodoAVL<Clave>* nodo2 = nodo1->get_der();
    nodo->get_izq() = nodo2->get_der();
    nodo2->get_der() = nodo;
    nodo1->get_der() = nodo2->get_izq();
    nodo2->get_izq() = nodo1;
    if (nodo2->get_bal() == -1)
        nodo1->set_bal(1);
    else 
        nodo1->set_bal(0);

    if (nodo2->get_bal() == 1)
        nodo->set_bal(-1);
    else 
        nodo->set_bal(0);
    
    nodo2->set_bal(0);
    nodo = nodo2;
}



template<class Clave>
void
AVL<Clave>::rotacionDI(nodoAVL<Clave>*& nodo) {
    nodoAVL<Clave>* nodo1 = nodo->get_der();
    nodoAVL<Clave>* nodo2 = nodo1->get_izq();
    nodo->get_der() = nodo2->get_izq();
    nodo2->get_izq() = nodo;
    nodo1->get_izq() = nodo2->get_der();
    nodo2->get_der() = nodo1;
    if (nodo2->get_bal() == 1)
        nodo1->set_bal(-1);
    else 
        nodo1->set_bal(0);

    if (nodo2->get_bal() == -1)
        nodo->set_bal(1);
    else 
        nodo->set_bal(0);
    
    nodo2->set_bal(0);
    nodo = nodo2;
}

#endif // AVL_HPP