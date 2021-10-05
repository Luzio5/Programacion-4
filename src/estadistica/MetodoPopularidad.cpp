#include <estadistica/MetodoPopularidad.hpp>

double MetodoPopularidad::getValor(Videojuego* videojuego) {
	return videojuego->getPopularidad();
}