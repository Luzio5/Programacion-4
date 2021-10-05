#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <set>
#include <string>
#include <estadistica/Metodo.hpp>
#include <Videojuego.hpp>

class Desarrollador;

class Estadistica {
    private:
        std::string nombre, descripcion;
        std::set<Desarrollador*> desarrolladores;
        Metodo* metodo;
    public:
		std::string getNombre();
		std::string getDescripcion();
		std::set<Desarrollador*> getDesarrolladores();
        double getValor(Videojuego*);
		Estadistica(std::string nombre, std::string descripcion, Metodo* metodo);
};

#endif
