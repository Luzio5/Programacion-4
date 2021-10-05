#ifndef DATA_JUGADOR_H
#define DATA_JUGADOR_H

#include <string>
#include <vector>

class DataJugador {
    private:
        std::string mail, contrasenia, nickname, descripcion;
    public:
        DataJugador(std::string mail, std::string contrasenia,std::string nickname, std::string descripcion);

        std::string getNickname() const;
        std::string getDescripcion() const;
};

#endif
