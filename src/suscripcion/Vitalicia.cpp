#include <suscripcion/Vitalicia.hpp>
#include <suscripcion/Suscripcion.hpp>

Vitalicia::Vitalicia(TipoFechaHora fechaHoraCompra, float costo, MetodoPago metodoPago, Jugador* jugadorAsociado, Videojuego* juegoAsociado)
    : Suscripcion(fechaHoraCompra, costo, metodoPago, jugadorAsociado, juegoAsociado) 
    , duracion(0)
    {}

bool Vitalicia::esActiva(){
    return true;
}

bool Vitalicia::estaSuscritoJugador(std::string nombre){
    std::string nom = this->getJugadorAsociado()->getnickname();
    return (nombre == nom); //&&esActiva(), que en este caso siempre es true.
}

int Vitalicia::getDuracionMes(){
    return this->duracion;
}

void Vitalicia::cancelarSus() {}