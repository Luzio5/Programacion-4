#ifndef UNIDOS_H
#define UNIDOS_H

#include <data/TipoFechaHora.hpp>
#include <cstddef>

class PartidaMultijugador;
class Jugador;

class Unidos {
    private:
        TipoFechaHora salida;
        bool esta;
        Jugador* jugador;
        PartidaMultijugador* partida;
    public:
		void setSalida(TipoFechaHora horaSalida);
        TipoFechaHora getHora();
        bool getEsta();
        Jugador* getJugador();
        PartidaMultijugador* getPartida();
        void setEsta(bool esta);
        void setJugador(Jugador* jugador);
        void setPartida(PartidaMultijugador* partida);
		Unidos(Jugador* jugador, PartidaMultijugador* partida);
};

#endif
