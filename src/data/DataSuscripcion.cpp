#include <data/DataSuscripcion.hpp>

DataSuscripcion::DataSuscripcion(TipoFechaHora fechaHoraCompra, float costo, int tipoDeSus, int duracion)
    : fechaHoraCompra(fechaHoraCompra)
    , costo(costo)
    , tipoDeSus(tipoDeSus)
    , duracion(duracion) {}


int DataSuscripcion::gettipoDeSus() {
    return this->tipoDeSus;
}

int DataSuscripcion::getduracion() {
    return this->duracion;
}

TipoFechaHora DataSuscripcion::getFechaHoraCompra() const {
    return this->fechaHoraCompra;
}

float DataSuscripcion::getCosto() const {
    return this->costo;
}

