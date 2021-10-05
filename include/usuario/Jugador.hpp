#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include <suscripcion/Suscripcion.hpp>
#include <usuario/Usuario.hpp>
#include <Puntos.hpp>
#include <Unidos.hpp>
#include <partida/Partida.hpp>

using namespace std;

class Jugador : public Usuario {
    private:
        string nickname;
        string descripcion;
        vector<Jugador*> sigueA;
        vector<Jugador*> seguidores;
        vector<Suscripcion*> suscripciones;
        vector<Puntos*> puntajes;
        vector<Unidos*> unidoAPartidasMultijugador;
        vector<Partida*> inicio;

    public:
        Jugador(string mail, string contrasenia, string nickname, string descripcion);

        // Propiedades

        string getnickname();
        void setnickname(string nickname);

        string getdescripcion();
        void setdescripcion(string descripcion);

        vector<Jugador*> getsigueA();
        void setsigueA(vector<Jugador*> sigueA);
        void agregarSigueA(Jugador*);
        Jugador* removerSigueA(Jugador*);

        vector<Jugador*> getseguidores();
        void setseguidores(vector<Jugador*> seguidores);
        void agregarSeguidores(Jugador*);
        Jugador* removerSeguidores(Jugador*);

        vector<Suscripcion*> getsuscripciones();
        void setsuscripciones(vector<Suscripcion*> suscripciones);

        vector<Puntos*> getpuntajes();
        void setpuntajes(vector<Puntos*> puntajes);
        void agregarPuntaje(Puntos*);

        vector<Unidos*> getunidoAPartidasMultijuador();
        void setunidoAPartidasMultijuador(vector<Unidos*> unidoAPartidasMultijuador);
        void agregarUnidoAPartidaM(Unidos* nuevaunion);

        vector<Partida*> getpartidasIniciadas();
        void agregarInicio(Partida* nuevapart);
        void removerInicio(Partida*);

        vector<Partida*> getinicio();
        void setinicio(vector<Partida*> inicio);

        void eliminarSuscripcion(Videojuego* v);

        // Utilidades.

        void linkearSuscripcionAJugador(Suscripcion*);
        vector<DataPartida> obtenerPartidasActuales();
        vector<DataPartida> obtenerPartidasIndFin();
        void finalizarJugador(Partida* partida);
        bool tieneSuscricpion(string juego);
        bool tieneSuscripcionActiva(string juego);
        Suscripcion* suscripcionAVideojuego(string juego);
        vector<DataVideojuego> obtenerVideojuegosSus();
        void cancelarSuscripcionAVideojuego(string nombreVid);  
        bool sonIguales(string nombre);
};

#endif