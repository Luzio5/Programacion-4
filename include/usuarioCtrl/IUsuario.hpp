#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <vector>
#include <string>
#include <data/DataVideojuego.hpp>
#include <data/DataJugador.hpp>
#include <data/DataPartidaIndividual.hpp>
#include <data/DataPartidaMultijugador.hpp>
#include <SistemHandler.hpp>
#include <Puntos.hpp>
#include <usuario/Jugador.hpp>
#include <Videojuego.hpp>
#include <partida/Partida.hpp>
#include <partida/PartidaIndividual.hpp>
#include <partida/PartidaMultijugador.hpp>
#include <Categoria.hpp>
#include <stdexcept>

class IUsuario {
    public:
        virtual std::vector<DataVideojuego> obtenerVideojuegosSus()=0;
        virtual std::vector<DataVideojuego> obtenerVideojuegosNoSus()=0;
        virtual std::vector<std::string> obtenerVideojuegosDesarrollador()=0;
        virtual std::vector<DataEstadistica> pedirEstadisticas(std::string)=0;
        virtual std::vector<DataPartida> obtenerPartidasIndFin()=0;
        virtual void crearJugador(std::string mail, std::string contrasenia, std::string nickname, std::string descripcion) = 0;
        virtual void crearDesarrollador(std::string mail, std::string contrasenia, std::string empresa) = 0;
        virtual Suscripcion* devuelveSiTieneSusActivaUsuarioQueInicioSesion(std::string videojuego, bool &res) = 0;
        virtual void crearPuntaje(int rating, std::string nick, std::string videojuego) = 0;
        virtual std::vector<DataPartidaMultijugador> obtenerPartidasMultiNoFinalizadas(std::string nick) = 0;
        virtual void salirPartidaMultijugador(int ident) = 0;
        virtual int iniciarSesion(std::string mail, std::string contrasenia) = 0; // True si es jugador, false si es desarrllador
        virtual void agregarCategoria(std::string nombre, std::string descripcion, int tipoDeCat) = 0;
};

#endif
