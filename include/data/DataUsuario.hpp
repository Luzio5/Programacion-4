#ifndef DATA_USUARIO_H
#define DATA_USUARIO_H

#include <string>
#include <vector>

class DataUsuario {
    private:
        std::string mail, contrasenia;
    public:
        DataUsuario(std::string mail, std::string contrasenia);

        std::string getMail() const;
        std::string getContrasenia() const;
};

#endif
