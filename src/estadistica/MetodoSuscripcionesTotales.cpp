#include <estadistica/MetodoSuscripcionesTotales.hpp>

double MetodoSuscripcionesTotales::getValor(Videojuego* videojuego){
	return videojuego->suscripcionesTotales();
}