#include <Categoria.hpp>

Categoria::Categoria(std::string nombre, std::string desc)
    : nombre(nombre)
    , descripcion(desc) {}

std::string Categoria::getNombre() const {
    return this->nombre;
}

void Categoria::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Categoria::getDescripcion() const {
    return this->descripcion;
}

void Categoria::setDescripcion(std::string desc) {
    this->descripcion = desc;
}

DataCategoria Categoria::getData() const {
    return DataCategoria(this->nombre, this->descripcion);
}
