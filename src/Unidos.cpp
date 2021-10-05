#include <Unidos.hpp>

void Unidos::setSalida(TipoFechaHora horaSalida){
	this->salida = horaSalida;
}

TipoFechaHora Unidos::getHora(){
	return salida;
}

bool Unidos::getEsta(){
	return esta;
}

Jugador* Unidos::getJugador(){
	return jugador;
}

PartidaMultijugador* Unidos::getPartida(){
	return partida;
}

Unidos::Unidos(Jugador* jugador, PartidaMultijugador* partida)
    : salida(0,0,0,0,0)
	, jugador(jugador)
	, partida(partida)
	, esta(true) {}

void Unidos::setEsta(bool esta) {
	this->esta = esta;
}

void Unidos::setJugador(Jugador* jugador) {
	this->jugador = jugador;
}

void Unidos::setPartida(PartidaMultijugador* partida) {
	this->partida = partida;
}

