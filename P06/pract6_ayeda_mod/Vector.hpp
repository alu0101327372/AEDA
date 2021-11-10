#ifndef VECTOR_HPP
#define VECTOR_HPP

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
#include "FuncionExploracion.hpp"

template<class Clave>
class Vector {
  public:
    Vector(int, FuncionDispersion<Clave>*&); // Inicializa la Vector
    ~Vector();

    bool Buscar(Clave&) const; // Busca la clave en la Vector
    bool Insertar(const Clave&); // Añade una clave a la Vector
    bool estaLlena() const;   // Comprueba si la Vector esta llena
    void Mostrar(); // Muestra los datos de la Vector

  private:
    int nSinonimos; // Contiene el tamaño de la Vector
    std::vector<Clave*> vDatos; // Array de nSinonimos posiciones
    FuncionDispersion<Clave>* fd; // Puntero a la clase base FuncionDispersion<Clave>
};


//Implementacion de los metodos
template<class Clave>
Vector<Clave>::Vector(int nClaves, FuncionDispersion<Clave>*& funcion) :
nSinonimos(nClaves), fd(funcion) {}



template<class Clave>
Vector<Clave>::~Vector() {
  //Liberamos la memoria
  for (int i = 0; i < vDatos.size(); i++)
    delete vDatos[i];
}



template<class Clave>
bool 
Vector<Clave>::Buscar(Clave& X) const {
  for(int i = 0; i < vDatos.size(); i++) {
    std::cout << *vDatos[i] << "\n";
    if(*vDatos[i] == X)
      return true;
  }

  // Si no esta llena entonces deberia insertarse la clave en esta celda
  if (!estaLlena())
    return true;
  return false;
}



template<class Clave>
bool 
Vector<Clave>::Insertar(const Clave& X) {
  // Comprobamos si está llena
  if(!estaLlena()) {
    vDatos.push_back(new Clave(X));
    return true;
  }

  // Si esta llena hay que utilizar un metodo de FExploracion 
  return false;
}



template<class Clave>
bool 
Vector<Clave>::estaLlena() const {
  if(vDatos.size() == nSinonimos)
    return true;
  return false;
}



template<class Clave>
void 
Vector<Clave>::Mostrar() {
  for(int i = 0; i < vDatos.size(); i++) {
    std::cout << *vDatos[i] << " | ";
  }
  std::cout << "\n";
}

#endif // VECTOR_HPP