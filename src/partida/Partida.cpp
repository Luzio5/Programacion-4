#include <partida/Partida.hpp>

Partida::Partida(TipoFechaHora fechaComienzo, Videojuego* deVideojuego, Jugador* creador, int ident) :
    fechaComienzo(fechaComienzo)
    ,duracion(0) //Para que la partida se inicie sin una duracion porque puede no estar finalizada
    ,deVideojuego(deVideojuego)
    ,creador(creador)
    ,ident(ident) {}

// Propiedades

void Partida::setfechaComienzo(TipoFechaHora fechaComienzo) {
    this->fechaComienzo = fechaComienzo;// LLAMAR VAR GLOBAL DE FECHA HORA
}

TipoFechaHora Partida::getfechaComienzo() const{
    return this->fechaComienzo;
}

void Partida::setduracion(float duracion) {
    this->duracion = duracion;
}

float Partida::getduracion() const {
    return this->duracion;
}

void Partida::setVideojuegoAsociado(Videojuego* deVideojuego) {
    this->deVideojuego = deVideojuego;
}

Videojuego* Partida::getVideojuegoAsociado() const {
    return this->deVideojuego;
}

void Partida::setJugadorCreador(Jugador* creador) {
    this->creador = creador;
}

Jugador* Partida::getJugadorCreador() {
    return this->creador;
}

int Partida::getident(){
    return this->ident;
}

void Partida::setident(int ident) {
    this->ident = ident;
}

float Partida::calcularDuracion(TipoFechaHora fecha)  {
    TipoFechaHora fechaComienzo = getfechaComienzo();
    float fechaComienzoReal = ((fechaComienzo.getAnio() * 525600) + (fechaComienzo.getMes() * 43200) + (fechaComienzo.getDia() * 1440) + (fechaComienzo.getHora() * 60) + (fechaComienzo.getMinuto()));
    float fechaReal = ((fecha.getAnio() * 525600) + (fecha.getMes() * 43200) + (fecha.getDia() * 1440) + (fecha.getHora() * 60) + (fecha.getMinuto()));
    return fechaReal - fechaComienzoReal;
}