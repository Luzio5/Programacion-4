#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H

#include <string>
#include <vector>
#include <Categoria.hpp>
#include <Videojuego.hpp>
#include <estadistica/Estadistica.hpp>
#include <data/DataEstadistica.hpp>

using namespace std;

class Desarrollador : public Usuario {
    private:
        std::string empresa;
        std::vector<Categoria*> categoriasCreadas;
        std::vector<Estadistica*> estadisticasSeleccionadas;
        std::vector<Videojuego*> videojuegosCreados;

    public:
        std::string getempresa();
        std::vector<Estadistica*> getestadisticas();
        std::vector<Categoria*> getcategoriasCreadas();
        std::vector<Videojuego*> getvideojuegos();
        void setempresa(string empresa);
        void setcategoriasCreadas(std::vector<Categoria*> categoriasCreadas);
        void setestadisticasSeleccionadas(std::vector<Estadistica*> estadisticasSeleccionadas);
        void setvideojuegosCreados(std::vector<Videojuego*> videojuegosCreados);
        void agergarCategoria(Categoria* categoria);
        void agergarEstadistica(Estadistica* estadistica);
        void agregarVideojuego(Videojuego* juego);
        std::vector<DataEstadistica> obtenerEstadisticaParaVideojuegoConcreto(Videojuego* videoJuego);
        std::vector<string> getnombreDeVideojuegosDesarrollados();
        Desarrollador(std::string mail, std::string contrasenia, std::string empresa);
        std::vector<DataPartida> obtenerPartidasActuales(); // NO HACE NADA EN ESTE CASO
};

#endif
