#include <data/DataComentario.hpp>

DataComentario::DataComentario(string texto, bool esRespuesta, int id, TipoFechaHora fechaEnvio)
    : texto(texto)
    , esRespuesta(esRespuesta)
    , identificador(id)
    , fechaEnvio(fechaEnvio) {}

string DataComentario::getTexto() const {
    return this->texto;
}

bool DataComentario::getEsRespuesta() const {
    return this->esRespuesta;
}

int DataComentario::getIdentificador() const {
    return this->identificador;
}

TipoFechaHora DataComentario::getFechaEnvio() const {
    return this->fechaEnvio;
}
