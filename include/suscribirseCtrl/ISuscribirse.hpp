#ifndef ISUSCRIBIRSE_H
#define ISUSCRIBIRSE_H

#include <string>
#include <suscripcion/Suscripcion.hpp>
#include <suscripcion/Vitalicia.hpp>
#include <suscripcion/Temporal.hpp>
#include <data/DataSuscripcion.hpp>
#include <SistemHandler.hpp>
// #include <data/DataPago.hpp>
#include <stdexcept>

class ISuscribirse {
    public:
        virtual DataSuscripcion* getsuscripcionQueSeEstaCreando() = 0;
        virtual void setsuscripcionQueSeEstaCreando(DataSuscripcion* suscripcionQueSeEstaCreando) = 0;
        virtual void setmetodoParaPagarSuscripcionCreada(MetodoPago metodoParaPagarSuscripcionCreada) = 0;
        virtual MetodoPago getmetodoParaPagarSuscripcionCreada() = 0;
        virtual std::string getnombreVideojuegoASuscribirse() = 0;
        virtual void setnombreVideojuegoASuscribirse(std::string nombre) = 0;
        virtual void cancelarSuscribirseAVideojuego() = 0;
        virtual void cancelarSuscripcionActual() = 0;
        virtual void confirmarAltaSuscripcion() = 0;
};

#endif
