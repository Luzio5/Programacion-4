#include <partida/PartidaIndividual.hpp>
#include <SistemHandler.hpp>
#include <stdexcept>

PartidaIndividual::PartidaIndividual(TipoFechaHora fechaComienzo, Videojuego* deVideojuego, Jugador* creador, int ident, bool continuaAnterior, Partida* continuacion)
  : Partida(fechaComienzo, deVideojuego, creador, ident)
  , continuaAnterior(continuaAnterior)
  , continuacion(continuacion)
  , esIndividual(true) {}


bool PartidaIndividual::getcontinuaAnterior() const {
    return this->continuaAnterior;
}

// Override

void PartidaIndividual::setcontinuaAnterior(bool continuaAnterior){
    this->continuaAnterior = continuaAnterior;
}

void PartidaIndividual::finalizarPartida() {
    TipoFechaHora fechaActual = SistemHandler::getInstancia()->getFechaSistema();
    float duracion = this->calcularDuracion(fechaActual);
    this->setduracion(duracion);
    //this->getJugadorCreador()->finalizarJugador(this);
}

float PartidaIndividual::getHorasJugadas() {
    return this->getduracion();
}

void PartidaIndividual::setesIndividual(bool esIndividual){
    this->esIndividual = esIndividual; //SIEMPRE ES TRUE!!!
}

bool PartidaIndividual::getesIndividual() {
    return this->esIndividual;
}

DataPartida PartidaIndividual::getData() {
    return DataPartida(getfechaComienzo(), getduracion(), getident(), getVideojuegoAsociado()->getNombre(), getJugadorCreador()->getnickname());
}

DataPartidaIndividual PartidaIndividual::getDataPartidaIndividual() {
    return DataPartidaIndividual(getfechaComienzo(), getduracion(), getident(), getVideojuegoAsociado()->getNombre(), getJugadorCreador()->getnickname(), getcontinuaAnterior());
}

DataPartidaMultijugador PartidaIndividual::getDataPartidaMultijugador() {
    throw std::logic_error("getDataPartidaMultijugador desde PartidaIndividual");
}

void PartidaIndividual::eliminarJugadores(Videojuego*v){
    creador->eliminarSuscripcion(v);
    creador->removerInicio(this);
}