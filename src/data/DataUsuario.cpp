#include <data/DataUsuario.hpp>


DataUsuario::DataUsuario(std::string mail, std::string contrasenia)
    : mail(mail)
    , contrasenia(contrasenia) {}

std::string DataUsuario::getMail() const {
    return this->mail;
}

std::string DataUsuario::getContrasenia() const {
    return this->contrasenia;
}