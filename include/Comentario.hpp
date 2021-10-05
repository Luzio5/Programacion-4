#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <vector>
#include <data/TipoFechaHora.hpp>
#include <data/DataComentario.hpp>

using namespace std;

class PartidaMultijugador;
class Usuario;

class Comentario {

    private:
        string texto;
        bool esRespuesta;
        int identificador;
        TipoFechaHora fechaEnvio;
        Comentario* respondeA;
        vector<Comentario*> respuestas;
        Usuario* autor;
        PartidaMultijugador* partida;

    public: 
        string getTexto();
        bool getEsRespuesta();
        int getIdentificador();
        TipoFechaHora getFechaEnvio();
        Comentario* getRespondeA();
        vector<Comentario*> getRespuestas();
        Usuario* getAutor();
        PartidaMultijugador* getPartida();
        DataComentario getDatos();
};

#endif
