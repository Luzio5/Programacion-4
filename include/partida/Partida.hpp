#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <data/TipoFechaHora.hpp>
#include <data/DataPartida.hpp>
#include <data/DataPartidaIndividual.hpp>
#include <data/DataPartidaMultijugador.hpp>

#include <usuario/Jugador.hpp>
#include <Videojuego.hpp>
#include <cassert> 

class Partida {
    protected:
        TipoFechaHora fechaComienzo;
        float duracion;
        Videojuego* deVideojuego;
        Jugador* creador;
        int ident;

    public:
        Partida(TipoFechaHora fechaComienzo, Videojuego* deVideojuego, Jugador* creador, int ident);

        // Propiedades
        void setfechaComienzo(TipoFechaHora);
        TipoFechaHora getfechaComienzo() const;

        void setduracion(float);
        float getduracion() const;

        void setVideojuegoAsociado(Videojuego*);
        Videojuego* getVideojuegoAsociado() const;

        void setJugadorCreador(Jugador*);
        Jugador* getJugadorCreador();

        void setident(int);
        int getident();

        // Metodos de utlidad.
        float calcularDuracion(TipoFechaHora);

        // Metodos comunes.
        virtual void finalizarPartida() = 0;
        virtual float getHorasJugadas() = 0;

        // Metodos de PartidaIndividual (en multijugador assert).
        virtual void setcontinuaAnterior(bool) = 0;

        // Para saber si es PartidaIndividual o PartidaMultijugador.
        virtual void setesIndividual(bool) = 0;
        virtual bool getesIndividual() = 0;

        // Datatypes de las partidas, si no tiene sentido en la subclase assert.
        virtual DataPartida getData() = 0;
        virtual DataPartidaIndividual getDataPartidaIndividual() = 0;
        virtual DataPartidaMultijugador getDataPartidaMultijugador() = 0;
        virtual void eliminarJugadores(Videojuego * v) = 0;
};

#endif
