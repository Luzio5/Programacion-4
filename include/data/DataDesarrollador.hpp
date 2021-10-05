#ifndef DATA_DESARROLLADOR_H
#define DATA_DESARROLLADOR_H

#include <string>

class DataDesarrollador {
    private:
        std::string empresa, mail, contrasenia;
    public:
        DataDesarrollador(std::string mail, std::string contrasenia, std::string empresa);

        std::string getEmpresa() const;
};

#endif