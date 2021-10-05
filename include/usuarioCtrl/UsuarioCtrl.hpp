#ifndef USUARIOCTRL_H
#define USUARIOCTRL_H

#include <usuarioCtrl/IUsuario.hpp>
#include <data/DataEstadistica.hpp>


class UsuarioCtrl : public IUsuario {
    public:
        virtual std::vector<DataVideojuego> obtenerVideojuegosSus();
        virtual std::vector<DataVideojuego> obtenerVideojuegosNoSus();
        virtual std::vector<std::string> obtenerVideojuegosDesarrollador();
        virtual std::vector<DataEstadistica> pedirEstadisticas(std::string);
        virtual std::vector<DataPartida> obtenerPartidasIndFin();
        virtual void crearJugador(std::string mail, std::string contrasenia, std::string nickname, std::string descripcion);
        virtual void crearDesarrollador(std::string mail, std::string contrasenia, std::string empresa);
        virtual Suscripcion* devuelveSiTieneSusActivaUsuarioQueInicioSesion(std::string videojuego, bool &res);     
        virtual void crearPuntaje(int rating, std::string nick, std::string videojuego);
        virtual std::vector<DataPartidaMultijugador> obtenerPartidasMultiNoFinalizadas(std::string nick);
        virtual void salirPartidaMultijugador(int ident);
        virtual int iniciarSesion(std::string mail, std::string contrasenia); // 0 si no existe, 1 si es jugador, 2 si es desarrllador
        virtual void agregarCategoria(std::string nombre, std::string descripcion, int tipoDeCat);
};

#endif