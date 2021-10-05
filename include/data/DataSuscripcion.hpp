#ifndef DATA_SUSCRIPCION_H
#define DATA_SUSCRIPCION_H

#include <data/DataVideojuego.hpp>
#include <data/DataJugador.hpp>
#include <data/MetodoPago.hpp>
#include <data/TipoFechaHora.hpp>

class DataSuscripcion {
    private:
        TipoFechaHora fechaHoraCompra;
        float costo;
        int tipoDeSus; // 0 Si es Vitalicia; 1 si es Temporal
        int duracion; // 0 Si es Vitalicia; 1, 3 o 12 si es Temporal
    public:
        DataSuscripcion(TipoFechaHora fechaHoraCompra, float costo, int tipoDeSus, int duracion);
        int gettipoDeSus();
        int getduracion();
        TipoFechaHora getFechaHoraCompra() const;
        float getCosto() const;
        MetodoPago getMetodoPago() const;
};

#endif
