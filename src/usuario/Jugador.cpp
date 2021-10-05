#include <usuario/Jugador.hpp>


Jugador::Jugador(std::string mail, std::string contrasenia, std::string nickname, std::string descripcion)
  : Usuario(mail, contrasenia)
  , nickname(nickname)
  , descripcion(descripcion) {
    std::vector<Jugador*> sigueA;
    std::vector<Jugador*> seguidores;
    std::vector<Suscripcion*> suscripciones;
    std::vector<Puntos*> puntajes;
    std::vector<Unidos*> unidos;
    std::vector<Partida*> inicio;
    this->sigueA = sigueA;
    this->seguidores = seguidores;
    this->suscripciones = suscripciones;
    this->puntajes = puntajes;
    this->unidoAPartidasMultijugador = unidos;
    this->inicio = inicio;
  }

// Propiedades

std::string Jugador::getnickname(){
    return this->nickname;
}

void Jugador::setnickname(std::string nickname) {
    this->nickname = nickname;
}

std::string Jugador::getdescripcion() {
    return this->descripcion;
}

void Jugador::setdescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

std::vector<Jugador*> Jugador::getsigueA() {
    return this->sigueA;
}

void Jugador::setsigueA(std::vector<Jugador*> sigueA) {
    this->sigueA = sigueA;
}

std::vector<Jugador*> Jugador::getseguidores() {
    return this->seguidores;
}

void Jugador::setseguidores(std::vector<Jugador*> seguidores) {
    this->seguidores = seguidores;
}

std::vector<Suscripcion*> Jugador::getsuscripciones() {
    return this->suscripciones;
}

void Jugador::setsuscripciones(std::vector<Suscripcion*> suscripciones) {
    this->suscripciones = suscripciones;
}

std::vector<Puntos*> Jugador::getpuntajes() {
    return this->puntajes;
}

std::vector<Unidos*> Jugador::getunidoAPartidasMultijuador() {
    return this->unidoAPartidasMultijugador;
}

std::vector<Partida*> Jugador::getpartidasIniciadas() {
    return this->inicio;
}

void Jugador::setpuntajes(std::vector<Puntos*> puntajes) {
    this->puntajes = puntajes;
}

void Jugador::setunidoAPartidasMultijuador(std::vector<Unidos*> unidoAPartidasMultijuador) {
    this->unidoAPartidasMultijugador = unidoAPartidasMultijugador;
}

void Jugador::setinicio(std::vector<Partida*> inicio) {
    this->inicio = inicio;
}

std::vector<DataPartida> Jugador::obtenerPartidasActuales() {
    std::vector<DataPartida> res;
    std::vector<Partida*> VectorPartidas = getpartidasIniciadas();
    for (int i=0; i< VectorPartidas.size(); i++) {
        if (VectorPartidas[i]->getduracion() != 0)
            res.push_back(VectorPartidas[i]->getData());
    }
    return res;
}

std::vector<DataPartida> Jugador::obtenerPartidasIndFin() {
    std::vector<DataPartida> res;
    std::vector<Partida*> VectorPartidas = getpartidasIniciadas();
    for (int i=0; i< VectorPartidas.size(); i++) {
        if (VectorPartidas[i]->getduracion() == 0 && VectorPartidas[i]->getesIndividual())
            res.push_back(VectorPartidas[i]->getData());
    }
    return res;
}

void Jugador::finalizarJugador(Partida* partida) {
    // TODO: terminar.
}

bool Jugador::tieneSuscricpion(std::string juego) {
    std::vector<Suscripcion*> vectorSus = getsuscripciones();
    int i=0;
    int j;
    bool res = false;
    while (i< vectorSus.size() && !res) {
        std::string nombre = vectorSus.at(i)->getVideojuegoAsociado()->getNombre();
        j = juego.compare(nombre);
        if (j == 0) {
            res = true;
        }
        i++;
    }
    //Habría que chequear si es activa o no. Pero hay que averiguar si es necesario
    return res;
}

bool Jugador::tieneSuscripcionActiva(std::string juego) {
    std::vector<Suscripcion*> vectorSus = getsuscripciones();
    int i=0;
    int j;
    bool res = false;
    while (i< vectorSus.size() && !res) {
        std::string nombre = vectorSus.at(i)->getVideojuegoAsociado()->getNombre();
        j = juego.compare(nombre);
        if (j == 0) {
            res = true;
        }
        if (res) {
            res = vectorSus.at(i)->esActiva();
        }
        i++;
    }
    return res;
}

Suscripcion* Jugador::suscripcionAVideojuego(std::string juego) {
    std::vector<Suscripcion*> vectorSus = getsuscripciones();
    int i=0;
    int j;
    bool res = false;
    Suscripcion* sus = nullptr;
    while (i< vectorSus.size() && !res) {
        std::string nombre = vectorSus.at(i)->getVideojuegoAsociado()->getNombre();
        j = juego.compare(nombre);
        if (j == 0) {
            res = true;
        }
        if (res) {
            sus = vectorSus.at(i);
        }
        i++;
    }
    return sus;
}

std::vector<DataVideojuego> Jugador::obtenerVideojuegosSus() {
    std::vector<Suscripcion*> VectorSuscripcion = getsuscripciones();
    std::vector<DataVideojuego> VectorVideojuego;
    for (int i=0; i< VectorSuscripcion.size(); i++) {
        if (VectorSuscripcion.at(i)->esActiva()) {
           Videojuego* videoj = VectorSuscripcion.at(i)->getVideojuegoAsociado();
           DataVideojuego data = videoj->getDatos();
           VectorVideojuego.insert(VectorVideojuego.end(), data);
        }
    }
    return VectorVideojuego;
}

void Jugador::cancelarSuscripcionAVideojuego(std::string nombreVid) {
    std::vector<Suscripcion*> VectorSuscripcion = getsuscripciones();
    bool encontre = false;
    int i = 0;
    while ((i< VectorSuscripcion.size()) && (encontre==false)) {
        std::string nombre = VectorSuscripcion.at(i)->getVideojuegoAsociado()->getNombre();
        if ((nombre.compare(nombreVid)==0) && (VectorSuscripcion.at(i)->esActiva())) {
            VectorSuscripcion.at(i)->cancelarSus();
            encontre = true;
        }
        i++;
    }    
}  

bool Jugador::sonIguales(std::string nombre) {
    int i = this->getnickname().compare(nombre);
    if (i==0) {
        return true;
    } else {
        return false;
    }
    
}

void Jugador::linkearSuscripcionAJugador(Suscripcion* nueva) {
    nueva->setJugadorAsociado(this);
    this->suscripciones.push_back(nueva);
}

void Jugador::agregarPuntaje(Puntos* p){
    puntajes.push_back(p);
}

void Jugador::agregarUnidoAPartidaM(Unidos* nuevaUnion){
    nuevaUnion->setJugador(this);
    unidoAPartidasMultijugador.push_back(nuevaUnion);
}


void Jugador::agregarInicio(Partida* nuevapart){
    inicio.push_back(nuevapart);
}

void Jugador::removerInicio(Partida* partida){
    std::vector<Partida*>::iterator it = inicio.begin();
    std::vector<Partida*>::iterator fin = inicio.end();

    while(((*it)->getident() != partida->getident())&&(it != fin)){
        advance(it,1);
    }
    if (it != fin){
        inicio.erase(it);
    }
}

void Jugador::eliminarSuscripcion(Videojuego* v){
    for (std::vector<Suscripcion*>::iterator itsus = suscripciones.begin(); itsus != suscripciones.end(); itsus++){
            if((*itsus)->getVideojuegoAsociado() == v) {
                delete (*itsus);
                suscripciones.erase(itsus);
                this->setsuscripciones(suscripciones);
            }
    }
}