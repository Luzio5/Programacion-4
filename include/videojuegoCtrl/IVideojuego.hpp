#ifndef IVIDEOJUEGO_H
#define IVIDEOJUEGO_H

#include <string>
#include <vector>
#include <data/DataCategoria.hpp>
#include <Videojuego.hpp>

class IVideojuego {
    public:
        virtual void ingresarDatos(std::string nombre, std::string descripcion)=0;
        virtual void ingresarCostosSuscripciones(int mensual, int trimestral, int anual, int vitalicia)=0;
        virtual std::vector<DataCategoria> obtenerGenerosExistentes()=0;
        virtual std::vector<DataCategoria> obtenerPlataformasExistentes()=0;
        virtual std::vector<DataCategoria> obtenerOtrasCatExistentes()=0;
        virtual void asignarGenero(std::string genero)=0;
        virtual void asignarPlataforma(std::string plataforma)=0;
        virtual void asignarCat(std::string otraCat)=0;
        virtual DataVideojuego obtenerDataVideojuegoAPublicar()=0;
        virtual void CancelarPublicacion()=0;
        virtual void ConfirmarPublicacion()=0;
        virtual std::vector<std::string> getgeneroenVcontroler()=0;
        virtual std::vector<std::string> getplataformaenVcontroler()=0;
        virtual std::vector<std::string> getotrasCatenVcontroler()=0;
};

#endif
