#ifndef VIDEOJUEGOCTRL_H
#define VIDEOJUEGOCTRL_H

#include <string>
#include <vector>
#include <videojuegoCtrl/IVideojuego.hpp>

class VideojuegoCtrl : public IVideojuego {
    private:
        std::string nombre, desc;
        int mensual, trimestral, anual, vitalicia;
        std::vector<std::string> genero, plataforma, categoria;
        bool tieneCategoria;
    public:
        VideojuegoCtrl();

        virtual void ingresarDatos(std::string nombre, std::string descripcion);
        virtual void ingresarCostosSuscripciones(int mensual, int trimestral, int anual, int vitalicia);
        virtual std::vector<DataCategoria> obtenerGenerosExistentes();
        virtual std::vector<DataCategoria> obtenerPlataformasExistentes();
        virtual std::vector<DataCategoria> obtenerOtrasCatExistentes();
        virtual void asignarGenero(std::string genero);
        virtual void asignarPlataforma(std::string plataforma);
        virtual void asignarCat(std::string otraCat);
        virtual DataVideojuego obtenerDataVideojuegoAPublicar();
        virtual void CancelarPublicacion();
        virtual void ConfirmarPublicacion();
        virtual std::vector<std::string> getgeneroenVcontroler();
        virtual std::vector<std::string> getplataformaenVcontroler();
        virtual std::vector<std::string> getotrasCatenVcontroler();
};

#endif
