#ifndef IPARTIDA_H
#define IPARTIDA_H

#include <vector>
#include <string>
#include <data/DataPartida.hpp>
#include <data/DataVideojuego.hpp>
#include <partida/Partida.hpp>
#include <stdexcept>

class IPartida {
    public:
        virtual std::vector<DataPartida> obtenerPartidasActuales() = 0;
        virtual void seleccionarPartida(int identificador) = 0;
        virtual void finalizarPartida() = 0;
        virtual void seleccionarVideojuego(std::string nombre) = 0;
        virtual void ingresarContinuacion(int identificador) = 0;
        virtual void identificadorPartidaIndNueva() = 0;
        virtual void transmitidaEnVivo(bool trans) = 0;
        virtual std::vector<std::string> jugadoresConSusActiva() = 0;
        virtual void agregarJugadores(std::string nick) = 0;
        virtual void identificadorPartidaMultiNueva() = 0;
        virtual void confirmarAltaPartida() = 0;
        virtual void cancelarAltaPartida() = 0;
        //virtual DataVideojuego getDataVideojuego() = 0;
        //virtual DataPartida getDataPartida() = 0;
        //virtual std::vector<std::string> getDataPartidaJugadoresUnidos() = 0;
        //virtual bool getDataPartidaEnVivo() = 0;
        //virtual bool getDataPartidaEsNueva() = 0;
        //virtual bool getDataPartidaEsMultijugador() = 0;
        //virtual int getDataPartidaIdent() = 0;
        //virtual Partida* Create() = 0;
};

#endif