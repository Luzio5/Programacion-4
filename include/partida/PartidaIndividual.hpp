#ifndef PARTIDA_INDIVIDUAL_H
#define PARTIDA_INDIVIDUAL_H

#include <string>
#include <partida/Partida.hpp>

class PartidaIndividual : public Partida {
    private:
        bool continuaAnterior;
        Partida* continuacion;
        bool esIndividual;
    public:
        PartidaIndividual(TipoFechaHora, Videojuego*, Jugador*, int, bool, Partida*);

        bool getcontinuaAnterior() const;

        // Override.
        void setcontinuaAnterior(bool);
        void finalizarPartida();
        float getHorasJugadas();
        void setesIndividual(bool);
        bool getesIndividual();
        DataPartida getData();
        DataPartidaIndividual getDataPartidaIndividual();
        DataPartidaMultijugador getDataPartidaMultijugador();
        void eliminarJugadores(Videojuego * v);
};

#endif
