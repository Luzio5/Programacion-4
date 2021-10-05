#ifndef SISTEM_H
#define SISTEM_H

#include <string>
#include <vector>
#include <usuario/Jugador.hpp>
#include <usuario/Desarrollador.hpp>
#include <data/DataVideojuego.hpp>
#include <data/DataPartida.hpp>
#include <data/DataCategoria.hpp>
#include <Videojuego.hpp>
#include <partida/Partida.hpp>
#include <data/TipoFechaHora.hpp>
#include <Categoria.hpp>
#include <partida/PartidaMultijugador.hpp>
#include <estadistica/Estadistica.hpp>
#include <estadistica/MetodoHorasJugadas.hpp>
#include <estadistica/MetodoPopularidad.hpp>
#include <estadistica/MetodoSuscripcionesTotales.hpp>
#include <suscripcion/Temporal.hpp>

class SistemHandler {
    private:
        int nuevoident; //es el ident disponible
        static SistemHandler* instancia;
        SistemHandler();
        TipoFechaHora fechaSistema;
		Usuario* inicioSesion;
        std::string mailDeUsuarioQueInicioSesion;
        std::string nicknameDeUsuarioQueInicioSesion; //Si es desarrollador que quede con 0
        std::string empresaDeUsuarioQueInicioSesion; //Si es jugador que quede con 0
        std::vector<Jugador*> listaJugador;
        std::vector<Desarrollador*> listaDesarrollador;
        std::vector<Videojuego*> listaVideojuego;
        std::vector<Partida*> listaPartida;//Revisar si no se precisa doble
        //std::vector<Categoria*> listaCategoria; // VER SI ES UTIL
        std::vector<Categoria*> listaGenero;
        std::vector<Categoria*> listaPlataforma;
        std::vector<Categoria*> listaOtrasCat;
        std::vector<Estadistica*> listaEstadistica;
        std::vector<Temporal*> listaSusTemporales;

    public:
        static SistemHandler* getInstancia();
        std::vector<DataVideojuego> getlistaDeVideojuegos();
        void addJugador(Jugador* jugador);
        void addDesarrollador(Desarrollador* jesarrollador);
        void agregarVideojuego(Videojuego* videojuego);
        void agregarPartida(Partida* partida);
        Jugador* obtenerJugadorDesdeMail(std::string mail);  // Devuelve puntero al jugador de mail "mail" para poder trabajar
        Desarrollador* obtenerDesarrolladorDesdeMail(std::string mail); // Devuelve puntero al desarrollador de mail "mail" para poder trabajar
        Partida* obtenerPartidaDesdeIdent(int identificador); // Devuelve puntero a la partida con identificador = ident
        Videojuego* obtenerVideojuegoDesdeNombre(std::string nombreDeVideojuego); //  Devuelve puntero al videojuego de nombre = nombreDeVideojuego
		Usuario* getUsuarioSesionActual();
        Jugador* getJugadorSesionActual();
        std::vector<DataVideojuego> obtenerVideojuegosSus(std::string nomJ);
        std::vector<DataVideojuego> obtenerVideojuegosNoSus(std::string nomJ);
        bool existeVideojuego(std::string NombreVideojuego);
        void cancelarSubscripcionActual(std::string Jugador, std::string Videojuego);
        void asociarSusJ(Suscripcion* s, std::string j);
        void asociarSusV(Suscripcion* s, std::string v);
        std::vector<DataPartida> obtenerPartidasIndividualesFinalizadas(std::string nomJ);
        bool existePartidaConIdentificador(int ident);
        int getIdentNuevo();
        std::vector<std::string> jugadoresConSusActiva(std::string VideojuegoNombre);
        void asociarParJ(Partida* p, std::string j);
        void asociarParV(Partida* p, std::string v);
        void asociarParJs(PartidaMultijugador* p, std::vector<std::string> jugadores);
        void continuarPartidaIndividual(int ident);
        std::vector<DataCategoria> getDataGeneros();
        std::vector<DataCategoria> getDataPlataformas();
        std::vector<DataCategoria> getDataOtrasCat();
        int getJugadoresConSuscripcion(std::string nombrejuego);
        void setFechaSistema(TipoFechaHora fecha);
        TipoFechaHora getFechaSistema() const;
        std::string getmailDeUsuarioQueInicioSesion();
        std::string getnicknameDeUsuarioQueInicioSesion();
        std::string getempresaDeUsuarioQueInicioSesion();
        void setmailDeUsuarioQueInicioSesion(std::string mail);
        void setnicknameDeUsuarioQueInicioSesion(std::string nickname);
        void setempresaDeUsuarioQueInicioSesion(std::string empresa);
        bool setteaSiExisteJugadorConMailYContrasenia(std::string mail,std::string contrasenia); // Si existe el jugador, devuelve true y settea el nick, mail del jugador y la empresa = 0. NECESARIO PARA CASO DE USO INICIAR SESION
        bool setteaSiExisteDesarrolladorConMailYContrasenia(std::string mail,std::string contrasenia); // Si existe el desarrollador, devuelve true y settea la empresa, mail del desarrollador y el nick = 0. NECESARIO PARA CASO DE USO INICIAR SESION
        bool existeJugadorConNickname(std::string nickname); // NECESARIO PARA CASO DE USO ALTA DE USUARIO
        bool existeDesarrolladorConMail(std::string mail); // PUEDE QUE NO SEA NECESARIA PARA NADA
        Estadistica* getEstadistica(std::string nombre);
        void inicializarEstadisticas();
        void addGenero(Categoria* categoria);
        void addPlataforma(Categoria* categoria);
        void addOtrasCat(Categoria* categoria);
        std::vector<std::string> obtenerVideojuegos();
        void confirmarEliminarVideojuego(std::string nombre);
        Categoria* getCategoria(std::string nombre);
        Categoria* getGenero(std::string nombre);
        Categoria* getPlataforma(std::string nombre);
        void agregarSuscripcion(Temporal*);

        std::vector<Desarrollador*> getDesarrolladores();
        std::vector<Jugador*> getJugadores();
        std::vector<Videojuego*> getVideojuegos();
        std::vector<Partida*> getPartidas();
        std::vector<Categoria*> getGeneros();
        std::vector<Categoria*> getPlataforma();
        std::vector<Categoria*> getOtrasCategorias();
        std::vector<Estadistica*> getEstadisticas();
};

#endif
