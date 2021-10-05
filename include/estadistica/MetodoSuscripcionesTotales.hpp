#ifndef METODO_SUSCRIPCIONES_TOTALES_H
#define METODO_SUSCRIPCIONES_TOTALES_H

#include <estadistica/Metodo.hpp>

class MetodoSuscripcionesTotales : public Metodo {
    public:
        double getValor(Videojuego* videojuego);
};

#endif