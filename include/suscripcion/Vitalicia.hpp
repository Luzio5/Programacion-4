#ifndef VITALICIA_H
#define VITALICIA_H

#include <string>
#include <Videojuego.hpp>
#include <usuario/Jugador.hpp>
#include <suscripcion/Suscripcion.hpp>

class Vitalicia: public Suscripcion {
    private:
        int duracion;
    public:
        virtual int getDuracionMes();
        Vitalicia(TipoFechaHora, float, MetodoPago, Jugador*, Videojuego*);
        virtual bool esActiva();
        virtual bool estaSuscritoJugador(std::string nombre); 
        virtual void cancelarSus();
};

#endif