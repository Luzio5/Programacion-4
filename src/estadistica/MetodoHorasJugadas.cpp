#include <estadistica/MetodoHorasJugadas.hpp>

double MetodoHorasJugadas::getValor(Videojuego* videojuego){
	double res = 0;
	set<Partida*> partidas = videojuego->getPartidas();
	set<Partida*>::iterator it;

	for (it = partidas.begin(); it != partidas.end(); it++) {
		res = res + (*it)->getHorasJugadas();
	}

	return res;
}
