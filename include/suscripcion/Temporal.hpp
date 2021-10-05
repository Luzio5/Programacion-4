#ifndef TEMPORAL_H
#define TEMPORAL_H

#include <string>
#include <Videojuego.hpp>
#include <usuario/Jugador.hpp>
#include <suscripcion/Suscripcion.hpp>


class Temporal: public Suscripcion{
    private:
        int duracionMes;
        bool cancelada;
        bool terminada;
    public:
        Temporal(TipoFechaHora, float, MetodoPago,
        Jugador*, Videojuego*, int, bool, bool);

        virtual int getDuracionMes();
        void setDuracionMes(int);

        bool getCancelada();
        void setCancelada(bool);

        bool getTerminada();
        void setTerminada(bool);

        void setearActividad(TipoFechaHora);

        virtual bool esActiva();
        virtual bool estaSuscritoJugador(std::string nombre);
        virtual void cancelarSus();
};

#endif
