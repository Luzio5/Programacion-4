#ifndef METODO_H
#define METODO_H

#include <Videojuego.hpp>

class Metodo {
    public:
        virtual double getValor(Videojuego* videojuego) = 0;
};

#endif