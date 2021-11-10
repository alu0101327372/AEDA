#ifndef TABLAHASH_HPP
#define TABLAHASH_HPP

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
#include "feLineal.hpp"
#include "feCuadratica.hpp"
#include "feDobleDispersion.hpp"
#include "feRedispersion.hpp"
#include "Vector.hpp"

template<class Clave>
class TablaHash {
    public:
        TablaHash(int, int, int, int); // Inicializa un objeto TablaHash
        ~TablaHash();

        bool Buscar(Clave&) const; // Busca la clave en la TablaHash de Tabla Hash
        bool Insertar(const Clave&); // Añade una clave a la TablaHash de Tabla Hash
        void Mostrar(); // Muestra cada Tabla Hash de la TablaHash

    private:   
        int nDatos; // Contiene el tamaño de la tabla
        std::vector<Vector<Clave> *> vDatos; // Array de nDatos posiciones
        FuncionDispersion<Clave>* fd; // Puntero a la clase base FuncionDispersion<Clave>    
        
        int nSinonimos; //  Tamaño del TablaHash ubicado en cada posición de la Tabla Hash
        FuncionExploracion<Clave>* fe; //  Puntero a la clase base FuncionExploracion<Clave>  
};



template<class Clave>
TablaHash<Clave>::TablaHash(int n, int k, int tipofd, int tipofe) : nDatos(n), nSinonimos(k) {
    // Crear la funcion de dispersion
    switch (tipofd) {
        case 0:
            fd = new fdModulo<Clave>(nDatos);
            for (int i = 0; i < nDatos; i++)
                vDatos.push_back(new Vector<Clave>(nSinonimos, fd));
            break;

        case 1:
            fd = new fdPseudoaleatoria<Clave>(nDatos);
            for (int i = 0; i < nDatos; i++)
                vDatos.push_back(new Vector<Clave>(nSinonimos, fd));
            break;
            
        default:
            break;
    }
    // Crear la funcion de exploracion
    switch (tipofe) {
        case 0:
            fe = new feLineal<Clave>();
            break;

        case 1:
            fe = new feCuadractica<Clave>();
            break;

        case 2:
            fe = new feDobleDispersion<Clave>(fd, nDatos);
            break;

        /*case 3:
            fe = new feRedispersion<Clave>(fd, nSinonimos);
            break;*/
            
        default:
            break;
    }
}



template<class Clave>
TablaHash<Clave>::~TablaHash() {
    for (int i = 0; i < vDatos.size(); i++)
        delete vDatos[i];
}



template<class Clave>
bool
TablaHash<Clave>::Buscar(Clave& X) const {
    // Buscar en la posicion que deberia encontrase.
    int pos = (*fd)(X);
    if (vDatos[pos]->Buscar(X)) {
        std::cout << "Clave: " << X << " - Pos: " << pos << " Ha sido encontrada!" << std::endl;
        return true;
    }

    // Buscar en posiciones respecto a la funcion de exploracion
    int i = 0;
    pos = ((*fd)(X) + (*fe)(X, i)) % nDatos;
    i++;
    while (!vDatos[pos]->Buscar(X)) {
        pos = ((*fd)(X) + (*fe)(X, i)) % nDatos;
        i++;
    }
    return true;
}



template<class Clave>
bool
TablaHash<Clave>::Insertar(const Clave& X) {
    //Hallamos la posicion de la Clave mediante la FDispersion
    int pos = (*fd)(X);
    std::cout << "Clave: " << X << " - Pos: " << pos << std::endl;

    int i = 0;
    while (!vDatos[pos]->Insertar(X)) {
        pos = ((*fd)(X) + (*fe)(X, i++)) % nDatos;
    }

    return true;
}



template<class Clave>
void
TablaHash<Clave>::Mostrar() {
    std::cout << "++++++++++++++\n";
    std::cout << "| Tabla Hash |\n";
    std::cout << "++++++++++++++\n";

    for (int i = 0; i < vDatos.size(); i++) {
        std::cout << i << " || ";
        vDatos[i]->Mostrar();
    }
}

#endif // TABLAHASH_HPP