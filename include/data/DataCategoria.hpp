#ifndef DATA_CATEGORIA_H
#define DATA_CATEGORIA_H

#include <string>

class DataCategoria {
    private:
        std::string nombre;
        std::string descripcion;
    public:
        DataCategoria(std::string nombre, std::string desc);

        std::string getNombre() const;
        std::string getDesc() const;
};

#endif
