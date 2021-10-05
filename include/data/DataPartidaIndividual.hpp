#ifndef DATA_PARTIDA_INDIVIDUAL_H
#define DATA_PARTIDA_INDIVIDUAL_H

#include <string>
#include <data/TipoFechaHora.hpp>

class DataPartidaIndividual {
    private:
        TipoFechaHora fechaComienzo;
        float duracion;
        int identificador;
        std::string nombreVideojuego;
        std::string creadorNickname;
        bool continuacion;
    public:
        DataPartidaIndividual(TipoFechaHora, float, int, std::string, std::string, bool);
        std::string getnombreVideojuego() const;
        TipoFechaHora getfechaComienzo() const;
        std::string getcreadorNickname() const;
        float getduracion() const;
        int getidentificador() const;
        bool getcontinuacion() const;
};

#endif