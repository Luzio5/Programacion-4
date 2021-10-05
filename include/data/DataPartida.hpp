#ifndef DATA_PARTIDA_H
#define DATA_PARTIDA_H

#include <string>
#include <data/TipoFechaHora.hpp>

class DataPartida {
    private:
        TipoFechaHora fechaComienzo;
        float duracion;
        int identificador;
        std::string nombreVideojuego;
        std::string creadorNickname;
    public:
        DataPartida(TipoFechaHora fechaComienzo, float duracion, int identificador, std::string nombreVideojuego, std::string creadorNickname);
        std::string getNombreVideojuego() const;
        std::string getCreadorNickname() const;
        float getDuracion() const;
        int getIdentificador() const;
        TipoFechaHora getFechaComienzo() const;
};

#endif