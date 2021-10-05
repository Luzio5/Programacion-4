#include <data/DataEstadistica.hpp>


DataEstadistica::DataEstadistica(std::string nombre, float valor)
:nombre(nombre)
,valor(valor) {}

std::string DataEstadistica::getnombre() const {
    return this->nombre;
}

float DataEstadistica::getvalor() const {
    return this->valor;
}