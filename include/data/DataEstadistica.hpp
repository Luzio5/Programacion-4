#ifndef DATA_ESTADISTICA_H
#define DATA_ESTADISTICA_H

#include <string>
#include <vector>

class DataEstadistica {
    private:
        std::string nombre;
        float valor;
    public:
        DataEstadistica(std::string nombre, float valor);

        std::string getnombre() const;
        float getvalor() const;
};

#endif