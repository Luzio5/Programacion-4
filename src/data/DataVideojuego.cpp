#include <data/DataVideojuego.hpp>

DataVideojuego::DataVideojuego(std::string nombre, 
    std::string desc, 
    std::string empresa,
    double popularidad, 
    int cantidadDePuntajes,
    std::vector<std::string> otrasCategorias,
    std::vector<std::string> plataformas,
    std::vector<std::string> generos, 
    DataCosto costo,
    double totalHorasJugadas)
    : nombre(nombre)
    , descripcion(desc)
    , empresa(empresa)
    , popularidad(popularidad)
    , cantidadDePuntajes(cantidadDePuntajes)
    , otrasCategorias(otrasCategorias)
    , plataformas(plataformas)
    , generos(generos)
    , costo(costo) 
    , totalHorasJugadas(totalHorasJugadas) {}

std::string DataVideojuego::getNombre() const {
    return this->nombre;
}

std::string DataVideojuego::getDescripcion() const {
    return this->descripcion;
}

std::string DataVideojuego::getEmpresa() const {
    return this->empresa;
}

double DataVideojuego::getPopularidad() const {
    return this->popularidad;
}

std::vector<std::string> DataVideojuego::getOtrasCategorias() const {
    return this->otrasCategorias;
}

std::vector<std::string> DataVideojuego::getPlataformas() const {
    return this->plataformas;
}

std::vector<std::string> DataVideojuego::getGeneros() const {
    return this->generos;
}

int DataVideojuego::getCantidadDePuntajes() const {
    return this->cantidadDePuntajes;
}

double DataVideojuego::gettotalHorasJugadas() const {
    return this->totalHorasJugadas;
}
      
DataCosto DataVideojuego::getCosto() const {
    return this->costo;
}