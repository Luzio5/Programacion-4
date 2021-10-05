#include <Videojuego.hpp>

void Videojuego::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Videojuego::getNombre() const {
    return this->nombre;
}

void Videojuego::setDescripcion(std::string desc) {
    this->descripcion = desc;
}

std::string Videojuego::getDescripcion() const {
    return this->descripcion;
}

void Videojuego::addCategoria(Categoria* categoria) {
    this->otrasCategorias.insert(categoria);
}

std::set<Categoria*> Videojuego::getOtrasCat() const {
    return this->generos;
}

void Videojuego::addGenero(Categoria* categoria) {
    this->generos.insert(categoria);
}

std::set<Categoria*> Videojuego::getGeneros() const {
    return this->generos;
}

void Videojuego::addPlataforma(Categoria* categoria) {
    this->plataformas.insert(categoria);
}

std::set<Categoria*> Videojuego::getPlataformas() const {
    return this->plataformas;
}

void Videojuego::agregarPartida(Partida* partida) {
    this->partidas.insert(partida);
}

void Videojuego::removerPartida(Partida* partida) {
    partidas.erase(partida);
}

std::set<Partida*> Videojuego::getPartidas() const {
    return this->partidas;
}

void Videojuego::agregarPuntaje(Puntos* puntos) {
    this->puntajes.insert(puntos);
}

void Videojuego::removerPuntaje(Puntos* puntos) {
    this->puntajes.erase(puntos);
}

std::set<Puntos*> Videojuego::getPuntos() const {
    return this->puntajes;
}

void Videojuego::agregarSuscripcion(Suscripcion* suscripcion) {
    this->suscripciones.insert(suscripcion);
}

void Videojuego::removerSuscripcion(Suscripcion* suscripcion) {
    this->suscripciones.erase(suscripcion);
}

std::set<Suscripcion*> Videojuego::getSuscripciones() const {
    return this->suscripciones;
}

void Videojuego::linkearVideojuegoASubscripcion(Suscripcion* s) {
    s->setVideojuegoAsociado(this);
    agregarSuscripcion(s);
}

void Videojuego::setCostoVitalicia(float vitalicia) {
    this->vitalicia = vitalicia;
}

float Videojuego::getCostoVitalicia() const {
    return this->vitalicia;
}

void Videojuego::setCostoMensual(float mensual) {
    this->mensual = mensual;
}

float Videojuego::getCostoMensual() const {
    return this->mensual;
}

void Videojuego::setCostoTrimestral(float trimestral) {
    this->trimestral = trimestral;
}

float Videojuego::getCostoTrimestral() const {
    return this->trimestral;
}

void Videojuego::setCostoAnual(float anual) {
    this->anual = anual;
}

float Videojuego::getCostoAnual() const {
   return this->anual;
}

std::vector<Jugador*> Videojuego::jugadoresConSubscripcionActiva() const {
    std::vector<Jugador*> ret;
    for (std::set<Suscripcion*>::iterator it = suscripciones.begin(); it != suscripciones.end(); it++) {
        if ((*it)->esActiva()) {
            ret.push_back((*it)->getJugadorAsociado());
        }
    }

    return ret;
}

bool Videojuego::noSubscrito(std::string nomJugador) const {
    std::set<Suscripcion*>::iterator it;

    for (it = suscripciones.begin(); it != suscripciones.end(); it++) {
        Jugador* j = (*it)->getJugadorAsociado();

        if (j->getnickname() == nomJugador)
            return false;
    }

    return true;
}

double Videojuego::totalHorasJugadas() const {
    double ret = 0;
    std::set<Partida*>::iterator it;

    for (it = partidas.begin(); it != partidas.end(); it++) {
        ret += (*it)->getduracion();
    }

    return ret;
}

int Videojuego::suscripcionesTotales() const {
    return suscripciones.size();
}

double Videojuego::getPopularidad() const {
    double ret = 0.0;
    std::set<Puntos*>::iterator it;

    for (it = puntajes.begin(); it != puntajes.end(); it++) {
        ret += (*it)->getRating();
    }

    ret /= puntajes.size();
    return ret;
}

DataVideojuego Videojuego::getDatos() const {
    DataCosto dc = DataCosto(getCostoVitalicia(), getCostoMensual(), getCostoTrimestral(), getCostoAnual());
    std::vector<std::string> otrasCategorias;
    std::vector<std::string> plataformas;
    std::vector<std::string> generos;

    for (std::set<Categoria*>::iterator it = this->otrasCategorias.begin(); it != this->otrasCategorias.end(); it++) {
        otrasCategorias.push_back((*it)->getNombre());
    }
    for(std::set<Categoria*>::iterator it = this->plataformas.begin(); it != this->plataformas.end(); it++){
        plataformas.push_back((*it)->getNombre());
    }
    for(std::set<Categoria*>::iterator it = this->generos.begin(); it != this->generos.end(); it++){
        generos.push_back((*it)->getNombre());
    }
    return DataVideojuego(getNombre(), 
        getDescripcion(), 
        empresa,
        getPopularidad(), 
        this->puntajes.size(), 
        otrasCategorias,
        plataformas,
        generos, 
        dc,
        totalHorasJugadas()); 
}

bool Videojuego::tienePartidaActiva(){
    std::set<Partida*>::iterator it = partidas.begin();
    std::set<Partida*>::iterator fin = partidas.end();
    while ((it!=fin)&&((*it)->getduracion()!=0))
        advance(it,1);
    if (it == fin){
        return false;
    }
    else{
        return true;
    }
}

void Videojuego::eliminarVideojuego(){
    std::set<Partida*>::iterator fin = partidas.end();
    for (std::set<Partida*>::iterator it = partidas.begin(); it != fin; advance(it,1)){
        (*it)->eliminarJugadores(this);
    }
    partidas.clear();
    //falta eliminar puntos
}

void Videojuego::setempresa(std::string empresa){
    this->empresa = empresa;
}

std::string Videojuego::getempresa() {
    return this->empresa;
}