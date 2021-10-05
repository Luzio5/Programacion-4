#include <data/DataPartidaMultijugador.hpp>


DataPartidaMultijugador::DataPartidaMultijugador(TipoFechaHora fechaComienzo, float duracion, int identificador, std::string nombreVideojuego, std::string creadorNickname, bool transmitidaEnVivo, std::vector<std::string> jugadoresUnidos)
 : fechaComienzo(fechaComienzo) 
 , duracion(duracion)
 , identificador(identificador)
 , nombreVideojuego(nombreVideojuego)
 , creadorNickname(creadorNickname)
 , transmitidaEnVivo(transmitidaEnVivo) 
 , jugadoresUnidos(jugadoresUnidos) {}



std::string DataPartidaMultijugador::getnombreVideojuego() const{
    return this->nombreVideojuego;
}

std::string DataPartidaMultijugador::getcreadorNickname() const {
    return this->creadorNickname;
}

TipoFechaHora DataPartidaMultijugador::getfechaComienzo() const{
    return this->fechaComienzo;
}

bool DataPartidaMultijugador::gettransmitidaEnVivo() const {
    return this->transmitidaEnVivo;
}

std::vector<std::string> DataPartidaMultijugador::getjugadoresUnidos() const {
    return this->jugadoresUnidos;
}

float DataPartidaMultijugador::getduracion() const {
    return this->duracion;
}

int DataPartidaMultijugador::getidentificador() const {
    return this->identificador;
}