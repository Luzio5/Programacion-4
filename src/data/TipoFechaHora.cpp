#include <data/TipoFechaHora.hpp>

TipoFechaHora::TipoFechaHora(int anio, int mes, int dia, int hora, int minuto)
    : anio(anio)
    , mes(mes)
    , dia(dia)
    , hora(hora)
    , minuto(minuto) {}

int TipoFechaHora::getAnio() const {
    return this->anio;
}

int TipoFechaHora::getMes() const {
    return this->mes;
}

int TipoFechaHora::getDia() const {
    return this->dia;
}

int TipoFechaHora::getHora() const {
    return this->hora;
}

int TipoFechaHora::getMinuto() const {
    return this->minuto;
}
