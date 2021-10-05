#ifndef METODO_HORAS_JUGADAS_H
#define METODO_HORAS_JUGADAS_H

#include <estadistica/Metodo.hpp>

class MetodoHorasJugadas : public Metodo {
    public:
        double getValor(Videojuego* videojuego);
};

#endif