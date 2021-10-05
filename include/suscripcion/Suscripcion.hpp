#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H

#include <string>
#include <data/DataVideojuego.hpp>
#include <data/MetodoPago.hpp>
#include <data/TipoFechaHora.hpp>

class Jugador;
class Videojuego;

class Suscripcion {
    private:
        bool esVitalica;
        float costo;
        MetodoPago metodoPago;
        Jugador* jugadorAsociado;
        Videojuego* juegoAsociado;
    protected:
        TipoFechaHora fechaHoraCompra;
    public:
        Suscripcion(TipoFechaHora, float, MetodoPago, Jugador*, Videojuego*);

        TipoFechaHora getFechaHoraCompra();
        void setFechaHoraCompra(TipoFechaHora);

        float getCosto();
        void setCosto(float);

        MetodoPago getMetodoPago();
        void setMetodoPago(MetodoPago);

        Jugador* getJugadorAsociado();
        void setJugadorAsociado(Jugador*);

        Videojuego* getVideojuegoAsociado();
        void setVideojuegoAsociado(Videojuego*);

        virtual int getDuracionMes()=0;
        virtual bool esActiva()=0;
        virtual bool estaSuscritoJugador(std::string nombre)=0;
        virtual void cancelarSus()=0;
};

#endif
