#ifndef LISTA_HPP
#define LISTA_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Tabla Hash
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include "fdModulo.hpp"
#include "fdPseudoaleatoria.hpp"
#include "TablaHash.hpp"

template<class Clave>
class Lista {
    public:
        Lista(int, int); // Inicializa un objeto Lista
        ~Lista();

        bool Buscar(Clave&) const; // Busca la clave en la lista de Tabla Hash
        bool Insertar(const Clave&); // Añade una clave a la lista de Tabla Hash
        void Mostrar(); // Muestra cada Tabla Hash de la Lista

    private:   
        int nDatos; // Contiene el tamaño de la tabla
        std::vector<TablaHash<Clave> *> vDatos; // Array de nDatos posiciones
        FuncionDispersion<Clave>* fd; // Puntero a la clase base FuncionDispersion<Clave>      
};



template<class Clave>
Lista<Clave>::Lista(int n, int tipofd) : nDatos(n) {
    switch (tipofd) {
        case 0:
            fd = new fdModulo<Clave>(nDatos);
            for (int i = 0; i < nDatos; i++)
                vDatos.push_back(new TablaHash<Clave>(nDatos, fd));
            break;

        case 1:
            fd = new fdPseudoaleatoria<Clave>(nDatos);
            for (int i = 0; i < nDatos; i++)
                vDatos.push_back(new TablaHash<Clave>(nDatos, fd));
            break;
            
        default:
            break;
    }
}



template<class Clave>
Lista<Clave>::~Lista() {
    for (int i = 0; i < vDatos.size(); i++)
        delete vDatos[i];
}



template<class Clave>
bool
Lista<Clave>::Buscar(Clave& X) const {
    // Buscar en la posicion que deberia encontrase.
    int pos = (*fd)(X);
    if (vDatos[pos]->Buscar(X)) {
        std::cout << "Clave: " << X << " - Pos: " << pos << " Ha sido encontrada!" << std::endl;
        return true;
    }
    else {
        std::cout << " No ha sido encontrada!" << std::endl;
        return false;
    }
}



template<class Clave>
bool
Lista<Clave>::Insertar(const Clave& X) {
    //Hallamos la posicion de la Clave mediante la FDispersion
    int pos = (*fd)(X);
    if (vDatos[pos]->Insertar(X)) {
        std::cout << "Clave: " << X << " - Pos: " << pos << std::endl;
        return true;
    }
    return false;
}



template<class Clave>
void
Lista<Clave>::Mostrar() {
    std::cout << "++++++++++++++\n";
    std::cout << "| Tabla Hash |\n";
    std::cout << "++++++++++++++\n";

    for (int i = 0; i < vDatos.size(); i++) {
        std::cout << i << " || ";
        vDatos[i]->Mostrar();
    }
}

#endif // LISTA_HPP