#include <data/DataJugador.hpp>


DataJugador::DataJugador(std::string mail, std::string contrasenia, std::string nickname, std::string descripcion)
    : mail(mail)
    , contrasenia(contrasenia)
    , nickname(nickname)
    , descripcion(descripcion) {}

std::string DataJugador::getNickname() const {
    return this->nickname;
}

std::string DataJugador::getDescripcion() const {
    return this->descripcion;
}
