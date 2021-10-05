#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <data/DataCategoria.hpp>
class Categoria{
    private:
        std::string nombre, descripcion;
    public:
        Categoria(std::string nombre, std::string desc);

        std::string getNombre() const;
        void setNombre(std::string);

        std::string getDescripcion() const;
        void setDescripcion(std::string);

        DataCategoria getData() const;
};

#endif
