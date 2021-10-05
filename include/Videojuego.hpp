#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <set>
#include <usuario/Jugador.hpp>
#include <data/DataVideojuego.hpp>
#include <Categoria.hpp>
#include <suscripcion/Suscripcion.hpp>

class Partida;
class Puntos;

class Videojuego {
    private:
        std::string nombre;
        std::string descripcion;
        std::string empresa;
        std::set<Categoria*> otrasCategorias;
        std::set<Categoria*> plataformas;
        std::set<Categoria*> generos;
	    std::set<Partida*> partidas;
	    std::set<Puntos*> puntajes;
        std::set<Suscripcion*> suscripciones;
        float vitalicia, mensual, trimestral, anual;

    public:
        void setNombre(std::string);
        std::string getNombre() const;

        void setDescripcion(std::string);
        std::string getDescripcion() const;

        void addCategoria(Categoria*);
        std::set<Categoria*> getOtrasCat() const;

        void addGenero(Categoria*);
        std::set<Categoria*> getGeneros() const;

        void addPlataforma(Categoria*);
        std::set<Categoria*> getPlataformas() const;

		void agregarPartida(Partida* partida);
        void removerPartida(Partida* partida);
		std::set<Partida*> getPartidas() const;

		void agregarPuntaje(Puntos*);
        void removerPuntaje(Puntos*);

		std::set<Puntos*> getPuntos() const;

		void agregarSuscripcion(Suscripcion*);
        void removerSuscripcion(Suscripcion*);
		std::set<Suscripcion*> getSuscripciones() const;
        void linkearVideojuegoASubscripcion(Suscripcion*);

        void setCostoVitalicia(float);
        float getCostoVitalicia() const;

        void setCostoMensual(float);
        float getCostoMensual() const;

        void setCostoTrimestral(float);
        float getCostoTrimestral() const;

        void setCostoAnual(float);
        float getCostoAnual() const;

        
        std::vector<Jugador*> jugadoresConSubscripcionActiva() const;
        bool noSubscrito(std::string nomJugador) const;
        double totalHorasJugadas() const;
        int suscripcionesTotales() const;
        double getPopularidad() const;
        DataVideojuego getDatos() const;

        bool tienePartidaActiva();
        void eliminarVideojuego();

        void setempresa(std::string empresa);
        std::string getempresa();
};

#endif
