#include <suscripcion/Temporal.hpp>
#include <suscripcion/Suscripcion.hpp>

Temporal::Temporal(TipoFechaHora fechaHoraCompra, float costo, MetodoPago metodoPago, Jugador* jugadorAsociado, Videojuego* juegoAsociado, int duracionMes, bool cancelada, bool terminada)
    : Suscripcion(fechaHoraCompra, costo, metodoPago, jugadorAsociado, juegoAsociado) //Utilizamos el constructor de la clase base
    , duracionMes(duracionMes) 
    , cancelada(cancelada)
    , terminada(terminada) {}

int Temporal::getDuracionMes(){
    return duracionMes;
}

void Temporal::setDuracionMes(int duracionMes){
    this->duracionMes = duracionMes;
}

bool Temporal::getCancelada(){
    return cancelada;
}

void Temporal::setCancelada(bool cancelada){
    this->cancelada = cancelada;
}

bool Temporal::getTerminada(){
    return terminada;
}

void Temporal::setTerminada(bool terminada){
    this->terminada = terminada;
}

bool Temporal::esActiva(){
    return (!terminada)&&(!cancelada);
}

bool Temporal::estaSuscritoJugador(std::string nombre){
    std::string nom = this->getJugadorAsociado()->getnickname();
    return (this->esActiva())&&(nom == nombre);
}

void Temporal::cancelarSus() {
    this->setCancelada(true);
}

void Temporal::setearActividad(TipoFechaHora fecha){
    float fechaComienzoReal = ((fechaHoraCompra.getAnio() * 525600) + (fechaHoraCompra.getMes() * 43200) + (fechaHoraCompra.getDia() * 1440) + (fechaHoraCompra.getHora() * 60) + (fechaHoraCompra.getMinuto()));
    float fechaFinalReal = ((fecha.getAnio() * 525600) + (fecha.getMes() * 43200) + (fecha.getDia() * 1440) + (fecha.getHora() * 60) + (fecha.getMinuto()));
    if (fechaFinalReal - fechaComienzoReal >= 43800*duracionMes){
        terminada = true;
    }
}