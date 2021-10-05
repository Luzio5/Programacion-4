#include <partida/PartidaMultijugador.hpp>
#include <SistemHandler.hpp>
#include <stdexcept>

PartidaMultijugador::PartidaMultijugador(TipoFechaHora fechaComienzo, Videojuego* deVideojuego, Jugador* creador, int ident, bool enVivo)
  : Partida(fechaComienzo, deVideojuego, creador, ident)
  , enVivo(enVivo) 
  , esIndividual(false) {}

// Override

void PartidaMultijugador::setcontinuaAnterior(bool b) {
    throw std::logic_error("setcontinuaAnterior desde PartidaMultijugador");
}

void PartidaMultijugador::finalizarPartida(){
    TipoFechaHora fechaActual = SistemHandler::getInstancia()->getFechaSistema();
    float duracion = this->calcularDuracion(fechaActual);
    this->setduracion(duracion);
    std::vector<Unidos*> VectorUnidos = getunidos();
    for (int i=0; i< VectorUnidos.size(); i++) {
      // VectorUnidos.at(i)->getJugador()->finalizarJugador(this);//Chequear nombre de finalizar operacion en Jugador
       VectorUnidos.at(i)->setSalida(fechaActual);
       VectorUnidos.at(i)->setEsta(false);
    }
}

float PartidaMultijugador::getHorasJugadas(){
    std::vector<Unidos*> VectorUnidos = getunidos();
    float duracion_total_sum_jugadores = 0;
    for (int i=0; i< VectorUnidos.size(); i++) {
       TipoFechaHora fechaDeSalida = VectorUnidos.at(i)->getHora();
       duracion_total_sum_jugadores = duracion_total_sum_jugadores + (calcularDuracion(fechaDeSalida));
    }
    duracion_total_sum_jugadores + getduracion();
    return duracion_total_sum_jugadores;
}

void PartidaMultijugador::setesIndividual(bool esIndividual){
    this->esIndividual = esIndividual;
}

bool PartidaMultijugador::getesIndividual(){
    return this->esIndividual;
}

DataPartida PartidaMultijugador::getData() {
    return DataPartida(getfechaComienzo(), getduracion(), getident(), getVideojuegoAsociado()->getNombre(), getJugadorCreador()->getnickname());
}

DataPartidaMultijugador PartidaMultijugador::getDataPartidaMultijugador() { 
    std::vector<Unidos*> VectorUnidos = getunidos();
    std::vector<std::string> JugadoresUnidos;
    for (int i = 0; i < VectorUnidos.size(); i++) {
       std::string nombre = VectorUnidos.at(i)->getJugador()->getnickname();
       JugadoresUnidos.insert(JugadoresUnidos.end(), nombre);
    }
    return DataPartidaMultijugador(getfechaComienzo(), getduracion(), getident(), getVideojuegoAsociado()->getNombre(), getJugadorCreador()->getnickname(), getenVivo(), JugadoresUnidos);
}

DataPartidaIndividual PartidaMultijugador::getDataPartidaIndividual() {
    throw std::logic_error("getDataPartidaIndividual desde PartidaMultijugador");
}

// Propiedades

void PartidaMultijugador::setenVivo(bool enVivo){
    this->enVivo = enVivo;
}

bool PartidaMultijugador::getenVivo(){
    return this->enVivo;
}

void PartidaMultijugador::setUnidos(std::vector<Unidos*> unidos){
    this->unidos=unidos;
}

void PartidaMultijugador::agregarUnidos(Unidos* unidos)  {
    unidos->setPartida(this);
    this->unidos.push_back(unidos);
}

std::vector<Unidos*> PartidaMultijugador::getunidos(){
    return this->unidos;
}

void PartidaMultijugador::eliminarJugadores(Videojuego * v){
    std::vector<Unidos*>::iterator fin = unidos.end();
    std::vector<Unidos*>::iterator itj;
    std::vector<Unidos*>::iterator finj;
    for (std::vector<Unidos*>::iterator it = unidos.begin(); it != fin; advance(it,1)){
        std::vector<Unidos*> uni = (*it)->getJugador()->getunidoAPartidasMultijuador();
        std::vector<Unidos*>::iterator itj = uni.begin();
        while (*itj != *it){
            itj++;
        }
        assert (*itj != nullptr);
        uni.erase(itj);
        Jugador* jug = (*it)->getJugador();
        jug->setunidoAPartidasMultijuador(uni);        
    }
    for (int i ; i< unidos.size(); i++) {
        delete unidos.at(i);
    }
    unidos.clear();
    creador->eliminarSuscripcion(v);
    creador->removerInicio(this);
}

