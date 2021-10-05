#ifndef DATA_VIDEOJUEGO_H
#define DATA_VIDEOJUEGO_H

#include <string>
#include <vector>
#include <data/DataCosto.hpp>

class DataVideojuego {
    private:
        std::string nombre;
        std::string descripcion;
        std::string empresa;
        double popularidad; // puntaje promedio
        int cantidadDePuntajes;
        std::vector<std::string> otrasCategorias;
        std::vector<std::string> plataformas;
        std::vector<std::string> generos;
        DataCosto costo;
        double totalHorasJugadas;
    public:
        DataVideojuego(std::string nombre, 
            std::string desc, 
            std::string empresa, 
            double popularidad, 
            int cantidadDePuntajes,
            std::vector<std::string> otrasCategorias,
            std::vector<std::string> plataformas,
            std::vector<std::string> generos,
            DataCosto costo,
            double totalHorasJugadas);

        double gettotalHorasJugadas() const;
        std::string getNombre() const;
        std::string getDescripcion() const;
        std::string getEmpresa() const;
        double getPopularidad() const;
        int getCantidadDePuntajes() const;
        std::vector<std::string> getOtrasCategorias() const;
        std::vector<std::string> getPlataformas() const;
        std::vector<std::string> getGeneros() const;
        DataCosto getCosto() const;
};

#endif
