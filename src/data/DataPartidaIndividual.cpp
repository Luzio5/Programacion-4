#include <data/DataPartidaIndividual.hpp>


DataPartidaIndividual::DataPartidaIndividual(TipoFechaHora fechaComienzo, float duracion, int identificador, std::string nombreVideojuego, std::string creadorNickname, bool continuacion)
 : fechaComienzo(fechaComienzo) 
 , duracion(duracion)
 , identificador(identificador)
 , nombreVideojuego(nombreVideojuego)
 , creadorNickname(creadorNickname)
 , continuacion(continuacion) {}

TipoFechaHora DataPartidaIndividual::getfechaComienzo() const {
    return this->fechaComienzo;
}

std::string DataPartidaIndividual::getnombreVideojuego() const{
    return this->nombreVideojuego;
}

std::string DataPartidaIndividual::getcreadorNickname() const {
    return this->creadorNickname;
}

float DataPartidaIndividual::getduracion() const {
    return this->duracion;
}

int DataPartidaIndividual::getidentificador() const {
    return this->identificador;
}

bool DataPartidaIndividual::getcontinuacion() const {
    return this->continuacion;
}