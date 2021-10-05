#include <suscribirseCtrl/SuscribirseCtrl.hpp>

SuscribirseCtrl::SuscribirseCtrl() {}

std::string SuscribirseCtrl::getnombreVideojuegoASuscribirse() {
    return nombreVideojuegoASuscribirse;
}

void SuscribirseCtrl::setnombreVideojuegoASuscribirse(std::string nombre) {
    SistemHandler* sys = SistemHandler::getInstancia();
    if (sys->existeVideojuego(nombre))
        this->nombreVideojuegoASuscribirse = nombre;
    else
        throw std::invalid_argument("No existe un Videojuego con ese nombre");
}

DataSuscripcion* SuscribirseCtrl::getsuscripcionQueSeEstaCreando() {
    return this->suscripcionQueSeEstaCreando;
}

void SuscribirseCtrl::setsuscripcionQueSeEstaCreando(DataSuscripcion* suscripcionQueSeEstaCreando) {
    this->suscripcionQueSeEstaCreando = suscripcionQueSeEstaCreando;
}

void SuscribirseCtrl::setmetodoParaPagarSuscripcionCreada(MetodoPago metodoParaPagarSuscripcionCreada) {
    this->metodoParaPagarSuscripcionCreada = metodoParaPagarSuscripcionCreada;
}

MetodoPago SuscribirseCtrl::getmetodoParaPagarSuscripcionCreada() {
    return this->metodoParaPagarSuscripcionCreada;
}

void SuscribirseCtrl::cancelarSuscribirseAVideojuego() {
    DataSuscripcion* sus = getsuscripcionQueSeEstaCreando();
    if ( sus != nullptr) {
       setsuscripcionQueSeEstaCreando(nullptr);
       delete sus;
    }
}

void SuscribirseCtrl::cancelarSuscripcionActual() {
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string nombreV = getnombreVideojuegoASuscribirse();
    std::string nombreJ = sys->getnicknameDeUsuarioQueInicioSesion();
    sys->cancelarSubscripcionActual(nombreJ, nombreV);
}

void SuscribirseCtrl::confirmarAltaSuscripcion() {
    MetodoPago pago = this->getmetodoParaPagarSuscripcionCreada();
    std::string nombreV = this->getnombreVideojuegoASuscribirse();
    DataSuscripcion* dataSus = this->getsuscripcionQueSeEstaCreando();
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string mailJ = sys->getmailDeUsuarioQueInicioSesion();
    std::string nombreJ = sys->getnicknameDeUsuarioQueInicioSesion();
    Videojuego* v = sys->obtenerVideojuegoDesdeNombre(nombreV);
    Jugador* j = sys->obtenerJugadorDesdeMail(mailJ);
    if (dataSus->gettipoDeSus() == 0 ) { // Vitalicia
        Vitalicia* s = new Vitalicia(dataSus->getFechaHoraCompra(), dataSus->getCosto(), pago, j, v);
        sys->asociarSusJ(s, nombreJ);
        sys->asociarSusV(s, nombreV);
    } else { // Temporal
        Temporal* t = new Temporal(dataSus->getFechaHoraCompra(), dataSus->getCosto(), pago, j, v, dataSus->getduracion(), false, false);
        sys->asociarSusJ(t, nombreJ);
        sys->asociarSusV(t, nombreV);
        sys->agregarSuscripcion(t);
    }
    this->cancelarSuscribirseAVideojuego();
}

