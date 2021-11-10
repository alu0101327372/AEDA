#ifndef TABLAHASH_HPP
#define TABLAHASH_HPP

/** 
 * University of La Laguna
 * Advanced Data Structures and Algorithms
 * Hormiga de Langton
 * @author Marco Antonio Cabrera Hernández
 * Contact: alu0101327372@ull.edu.es
 * Compilation: g++ -std=c++11 -g -Wall main.cpp -o main
 */

#include <vector>
#include "FuncionDispersion.hpp"

template<class Clave>
class TablaHash {
  public:
    TablaHash(int, FuncionDispersion<Clave>*&); // Inicializa la Tabla Hash
    ~TablaHash();

    bool Buscar(Clave&) const; // Busca la clave en la Tabla Hash
    bool Insertar(const Clave&); // Añade una clave a la Tabla Hash
    bool estaLlena() const;   // Comprueba si la TablaHash esta llena
    void Mostrar(); // Muestra los datos de la TablaHash

  private:
    int nDatos; // Contiene el tamaño de la Tabla Hash
    std::vector<Clave*> vDatos; // Array de nDatos posiciones
    FuncionDispersion<Clave>* fd; // Puntero a la clase base FuncionDispersion<Clave>
};


//Implementacion de los metodos
template<class Clave>
TablaHash<Clave>::TablaHash(int nClaves, FuncionDispersion<Clave>*& funcion) :
nDatos(nClaves), fd(funcion) {}



template<class Clave>
TablaHash<Clave>::~TablaHash() {
  //Liberamos la memoria
  for (int i = 0; i < vDatos.size(); i++)
    delete vDatos[i];
}



template<class Clave>
bool 
TablaHash<Clave>::Buscar(Clave& X) const {
  for(int i = 0; i < vDatos.size(); i++) {
    std::cout << *vDatos[i] << "\n";
    if(*vDatos[i] == X)
      return true;
  }
  return false;
}



template<class Clave>
bool 
TablaHash<Clave>::Insertar(const Clave& X) {
  // Al ser dispersión abierta nunca esta llena
  if(!estaLlena()) {
    vDatos.push_back(new Clave(X));
    return true;
  }
  return false;
}



template<class Clave>
bool 
TablaHash<Clave>::estaLlena() const {
  if(vDatos.size() == nDatos)
    return true;
  return false;
}



template<class Clave>
void 
TablaHash<Clave>::Mostrar() {
  for(int i = 0; i < vDatos.size(); i++) {
    std::cout << *vDatos[i] << " | ";
  }
  std::cout << "\n";
}

#endif // TABLAHASH_HPP