#include <suscripcion/Suscripcion.hpp>

Suscripcion::Suscripcion(TipoFechaHora fechaHoraCompra, float costo, MetodoPago metodoPago, Jugador* jugadorAsociado, Videojuego* juegoAsociado)
    : fechaHoraCompra(fechaHoraCompra)
    , costo(costo)
    , metodoPago(metodoPago)
    , jugadorAsociado(jugadorAsociado)
    , juegoAsociado(juegoAsociado) {}

TipoFechaHora Suscripcion::getFechaHoraCompra(){
    return fechaHoraCompra;
}

void Suscripcion::setFechaHoraCompra(TipoFechaHora fechaHoraCompra){
    this->fechaHoraCompra = fechaHoraCompra;
}

float Suscripcion::getCosto(){
    return costo;
}

void Suscripcion::setCosto(float costo){
    this->costo = costo;
}

MetodoPago Suscripcion::getMetodoPago(){
    return metodoPago;
}

void Suscripcion::setMetodoPago(MetodoPago metodoPago){
    this->metodoPago = metodoPago;
}

Jugador* Suscripcion::getJugadorAsociado(){
    return jugadorAsociado;
}

void Suscripcion::setJugadorAsociado(Jugador* jugadorAsociado){
    this->jugadorAsociado = jugadorAsociado;
}

Videojuego* Suscripcion::getVideojuegoAsociado(){
    return juegoAsociado;
}

void Suscripcion::setVideojuegoAsociado(Videojuego* juegoAsociado){
    this->juegoAsociado = juegoAsociado;
}
