#include <partidaCtrl/PartidaCtrl.hpp>
#include <partida/PartidaIndividual.hpp>
#include <partida/PartidaMultijugador.hpp>
#include <usuario/Jugador.hpp>
#include <SistemHandler.hpp>
#include <iostream>


//iniciar partida

std::string PartidaCtrl::getVideojuegoPartidaACrear(){
	return *videojuegoPartidaACrear;
}

bool PartidaCtrl::getIndividual(){
	return individual;
}

bool PartidaCtrl::getContinuacion(){
	return continuacion;
}

int PartidaCtrl::getIdent(){
	return *ident;
}

bool PartidaCtrl::getEnVivo(){
	return enVivo;
}

std::vector<std::string> PartidaCtrl::getJugadoresUnidos(){
	return this->jugadoresUnidos;
}

void PartidaCtrl::seleccionarVideojuego(std::string nombre){
	SistemHandler* sh = SistemHandler::getInstancia();
	bool valido = sh->existeVideojuego(nombre);
	if(valido){
		videojuegoPartidaACrear =  new string;
		*videojuegoPartidaACrear = nombre;
	}
	else {
		throw std::invalid_argument("No existe videojuego");
		
	}
}

void PartidaCtrl::ingresarContinuacion(int identificador){
	SistemHandler* sh = SistemHandler::getInstancia();
	bool valido = sh->existePartidaConIdentificador(identificador);
	if(valido){
		individual = true;
		continuacion = true;
		ident =  new int;
		*ident = identificador;
	}
	else{
		throw std::invalid_argument("No existe partida con ese identificador.");
	}
}

void PartidaCtrl::identificadorPartidaIndNueva(){
	SistemHandler* sh = SistemHandler::getInstancia();
	ident = new int;
	*ident = sh->getIdentNuevo();
	continuacion = false;
	individual = true;
}

void PartidaCtrl::transmitidaEnVivo(bool trans){
	enVivo = trans;
}

std::vector<std::string> PartidaCtrl::jugadoresConSusActiva(){
	SistemHandler* sh = SistemHandler::getInstancia();
	std::vector<std::string> jugadores = sh->jugadoresConSusActiva(*videojuegoPartidaACrear);
	return jugadores;
}

void PartidaCtrl::agregarJugadores(std::string nick){
	jugadoresUnidos.push_back(nick);
}

void PartidaCtrl::identificadorPartidaMultiNueva(){
	SistemHandler* sh = SistemHandler::getInstancia();
	ident = new int;
	*ident = sh->getIdentNuevo();
	individual = false;
}

void PartidaCtrl::cancelarAltaPartida(){
	jugadoresUnidos.clear();
	delete ident;
	delete videojuegoPartidaACrear;
}

void PartidaCtrl::confirmarAltaPartida(){
	SistemHandler* sh = SistemHandler::getInstancia();
	if(individual){
		PartidaIndividual* partida = new PartidaIndividual(sh->getFechaSistema(), sh->obtenerVideojuegoDesdeNombre(*videojuegoPartidaACrear), sh->obtenerJugadorDesdeMail(sh->getmailDeUsuarioQueInicioSesion()), *ident, continuacion, sh->obtenerPartidaDesdeIdent(*ident));
		sh->agregarPartida(partida);
		sh->obtenerVideojuegoDesdeNombre(*videojuegoPartidaACrear)->agregarPartida(partida);
		sh->obtenerJugadorDesdeMail(sh->getmailDeUsuarioQueInicioSesion())->agregarInicio(partida); //
	}
	else{
		PartidaMultijugador* partida = new PartidaMultijugador(sh->getFechaSistema(), sh->obtenerVideojuegoDesdeNombre(*videojuegoPartidaACrear), sh->obtenerJugadorDesdeMail(sh->getmailDeUsuarioQueInicioSesion()), *ident, enVivo);
		sh->asociarParJs(partida, jugadoresUnidos);
		sh->agregarPartida(partida);
		sh->obtenerVideojuegoDesdeNombre(*videojuegoPartidaACrear)->agregarPartida(partida); //
		sh->obtenerJugadorDesdeMail(sh->getmailDeUsuarioQueInicioSesion())->agregarInicio(partida); //
	}
	jugadoresUnidos.clear();
	delete ident;
	delete videojuegoPartidaACrear;
}


	


//finalizar partida

std::vector<DataPartida> PartidaCtrl::obtenerPartidasActuales(){
	SistemHandler* sh = SistemHandler::getInstancia();
	Usuario* jugador = sh->obtenerJugadorDesdeMail(sh->getmailDeUsuarioQueInicioSesion()); 
	return jugador->obtenerPartidasActuales(); //Llamamos la funcion sobre un usuario. Dará problema?
}

void PartidaCtrl::seleccionarPartida(int identificador){
	ident = new int;
	*ident = identificador;
}

void PartidaCtrl::finalizarPartida(){
	SistemHandler* sh = SistemHandler::getInstancia();
	Partida* aFinalizar = sh->obtenerPartidaDesdeIdent(*ident);
	aFinalizar->finalizarPartida();
}



	