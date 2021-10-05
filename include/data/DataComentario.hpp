#ifndef DATACOMENTARIO_H
#define DATACOMENTARIO_H

#include <string>
#include <data/TipoFechaHora.hpp>

using namespace std;

class DataComentario {
    private:
        string texto;
        bool esRespuesta;
        int identificador;
        TipoFechaHora fechaEnvio;
    public:
        DataComentario(string texto, bool esRespuesta, int id, TipoFechaHora fechaEnvio);

        string getTexto() const;
        bool getEsRespuesta() const;
        int getIdentificador() const;
        TipoFechaHora getFechaEnvio() const;
};

#endif
