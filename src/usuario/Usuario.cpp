#include <usuario/Usuario.hpp>

Usuario::Usuario(std::string mail, std::string contrasenia)
    : mail(mail)
    , contrasenia(contrasenia) {}

std::string Usuario::getmail() {
    return this->mail;
}

void Usuario::setmail(std::string mail) {
    this->mail = mail;
}

std::string Usuario::getcontrasenia() {
    return this->contrasenia;
}

void Usuario::setcontrasenia(std::string contrasenia) {
    this->contrasenia = contrasenia;
}
