#include <data/DataPartida.hpp>


DataPartida::DataPartida(TipoFechaHora fechaComienzo, float duracion, int identificador, std::string nombreVideojuego, std::string creadorNickname) 
    : fechaComienzo(fechaComienzo)
    , duracion(duracion)
    , identificador(identificador)
    , nombreVideojuego(nombreVideojuego)
    , creadorNickname(creadorNickname) {}

std::string DataPartida::getNombreVideojuego() const {
    return this->nombreVideojuego;
}

std::string DataPartida::getCreadorNickname() const {
    return this->creadorNickname;
}

float DataPartida::getDuracion() const {
    return this->duracion;
}

int DataPartida::getIdentificador() const {
    return this->identificador;
}

TipoFechaHora DataPartida::getFechaComienzo() const {
    return this->fechaComienzo;
}