#include <data/DataDesarrollador.hpp>


DataDesarrollador::DataDesarrollador(std::string mail, std::string contrasenia, std::string empresa)
   : mail(mail)
   , contrasenia(contrasenia)
   , empresa(empresa) {}


std::string DataDesarrollador::getEmpresa() const {
    return this->empresa;
}


