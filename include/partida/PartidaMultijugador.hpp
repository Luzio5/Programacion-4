#ifndef PARTIDA_MULTIJUGADOR_H
#define PARTIDA_MULTIJUGADOR_H

#include <string>
#include <vector>
#include <partida/Partida.hpp>
#include <data/DataPartida.hpp>
#include <Comentario.hpp>
#include <Unidos.hpp>

class PartidaMultijugador : public Partida {
    private:
        bool enVivo;
        std::vector<Unidos*> unidos;
        bool esIndividual;
    public:
        PartidaMultijugador(TipoFechaHora, Videojuego*, Jugador*, int, bool);

        // Override
        void setcontinuaAnterior(bool);
        void finalizarPartida();
        float getHorasJugadas();
        void setesIndividual(bool);
        bool getesIndividual();
        DataPartida getData();
        DataPartidaIndividual getDataPartidaIndividual();
        DataPartidaMultijugador getDataPartidaMultijugador();

        // Propiedades
        void setenVivo(bool);
        bool getenVivo();

        void setUnidos(std::vector<Unidos*>);
        void agregarUnidos(Unidos*);
        std::vector<Unidos*> getunidos();

        void eliminarJugadores(Videojuego * v);
};

#endif