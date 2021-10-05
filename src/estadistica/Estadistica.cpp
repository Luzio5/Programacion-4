#include <estadistica/Estadistica.hpp>

std::string Estadistica::getNombre(){
	return nombre;
}

std::string Estadistica::getDescripcion(){
	return this->descripcion;
}

std::set<Desarrollador*> Estadistica::getDesarrolladores(){
	return this->desarrolladores;
}

double Estadistica::getValor(Videojuego* juego){
	return metodo->getValor(juego);
}

Estadistica::Estadistica(std::string nombre, std::string descripcion, Metodo* metodo){
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->metodo = metodo;
}
