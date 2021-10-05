#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <data/DataPartida.hpp>

class Usuario {
    private:
        std::string mail;
        std::string contrasenia;
    public:
        Usuario(std::string mail, std::string contrasenia);

        std::string getmail();
        void setmail(std::string mail);

        std::string getcontrasenia();
        void setcontrasenia(std::string contrasenia);

        virtual std::vector<DataPartida> obtenerPartidasActuales() = 0;
};

#endif
