#include <Puntos.hpp>

int Puntos::getRating(){
	return rating;
}

Jugador* Puntos::getJugador(){
	return jugador;
}

Videojuego* Puntos::getJuego(){
	return juego;
}

Puntos::Puntos(int rating, Jugador* jugador, Videojuego* juego){
	this->rating = rating;
	this->jugador = jugador;
	this->juego = juego;
}