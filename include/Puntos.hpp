#ifndef PUNTOS_H
#define PUNTOS_H

#include <usuario/Jugador.hpp>
#include <Videojuego.hpp>

class Puntos {

    private:
        int rating;
        Jugador* jugador;
        Videojuego* juego;

    public: 
        int getRating();
        Jugador* getJugador();
        Videojuego* getJuego();
        Puntos(int rating, Jugador* jugador, Videojuego* juego);
};

#endif