#ifndef SUSCRIBIRSECTRL_H
#define SUSCRIBIRSECTRL_H
 
#include <string>
#include <suscripcion/Suscripcion.hpp>
//#include <data/DataSuscripcion.hpp>
#include <suscribirseCtrl/ISuscribirse.hpp>
// #include <data/DataPago.hpp>
#include <stdexcept>

class SuscribirseCtrl: public ISuscribirse {
    private:
        std::string nombreVideojuegoASuscribirse;
        DataSuscripcion* suscripcionQueSeEstaCreando;
        MetodoPago metodoParaPagarSuscripcionCreada;

    public: 
        SuscribirseCtrl();
        virtual DataSuscripcion* getsuscripcionQueSeEstaCreando();
        virtual void setsuscripcionQueSeEstaCreando(DataSuscripcion* suscripcionQueSeEstaCreando);
        virtual void setmetodoParaPagarSuscripcionCreada(MetodoPago metodoParaPagarSuscripcionCreada);
        virtual MetodoPago getmetodoParaPagarSuscripcionCreada();
        virtual std::string getnombreVideojuegoASuscribirse();
        virtual void setnombreVideojuegoASuscribirse(std::string nombre);
        virtual void cancelarSuscribirseAVideojuego();
        virtual void cancelarSuscripcionActual();
        virtual void confirmarAltaSuscripcion();
};

#endif