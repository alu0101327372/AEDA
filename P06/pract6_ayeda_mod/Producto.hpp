#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <string>

class Producto {
    
private:
    long int codigo;
    std::string name;
    int precio;
    
public:
    
    Producto(void){
        codigo = 0;
    }
    
    Producto (long int producto, std::string nombre, int p){
        codigo = producto;
        name = nombre;
        precio = p;
    }

    Producto (long int producto){
        codigo = producto;
    }
    
    long int producto(void){
        return codigo;
    }

    std::string get_name(void) const {
    	return name;
    }

    int get_precio(void) const {
        return precio;
    }

    void set_name(std::string name_){
    	name = name_;
    }

    void set_precio(int p) {
        precio = p;
    }
    
    long int operator% (const int& num){
        long int resultado = codigo % num;
        return resultado;
    }
    
    void operator= (const int& num){
        codigo = num;
    }
    
    bool operator== (const Producto& other) const {
        if (codigo == other.codigo)
            return true;
        else
            return false;
    }
    
    bool operator== (const int& num) const {
        if (codigo == num)
            return true;
        else
            return false;
    }
    
    
    bool operator!= (const Producto& other){
        if (this->codigo == other.codigo)
            return false;
        else
            return true;
    }

    
    operator long int () const{
        return codigo;
    }
    
};