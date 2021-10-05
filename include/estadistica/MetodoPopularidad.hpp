#ifndef METODO_POPULARIDAD_H
#define METODO_POPULARIDAD_H

#include <estadistica/Metodo.hpp>

class MetodoPopularidad : public Metodo {
    public:
        double getValor(Videojuego* videojuego);
};

#endif