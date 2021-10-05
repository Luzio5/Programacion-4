#include <data/DataCategoria.hpp>

DataCategoria::DataCategoria(std::string nombre, std::string desc)
    : nombre(nombre)
    , descripcion(desc) {}

std::string DataCategoria::getNombre() const {
    return this->nombre;
}

std::string DataCategoria::getDesc() const {
    return this->descripcion;
}
