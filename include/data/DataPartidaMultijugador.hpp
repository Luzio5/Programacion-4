#ifndef DATA_PARTIDA_MULTIJUGADOR_H
#define DATA_PARTIDA_MULTIJUGADOR_H

#include <string>
#include <vector>
#include <data/TipoFechaHora.hpp>

class DataPartidaMultijugador {
    private:
        TipoFechaHora fechaComienzo;
        float duracion;
        int identificador;
        std::string nombreVideojuego;
        std::string creadorNickname;
        bool transmitidaEnVivo;
        std::vector<std::string> jugadoresUnidos; 
    public:
        DataPartidaMultijugador(TipoFechaHora, float, int, std::string, std::string, bool, std::vector<std::string>);
        std::string getnombreVideojuego() const;
        std::string getcreadorNickname() const;
        float getduracion() const;
        int getidentificador() const;
        bool gettransmitidaEnVivo() const;
        TipoFechaHora getfechaComienzo() const; 
        std::vector<std::string> getjugadoresUnidos() const;
};

#endif