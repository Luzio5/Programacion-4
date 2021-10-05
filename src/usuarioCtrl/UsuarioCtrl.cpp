#include <usuarioCtrl/UsuarioCtrl.hpp>

std::vector<DataVideojuego> UsuarioCtrl::obtenerVideojuegosSus() {
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string nickname = sys->getnicknameDeUsuarioQueInicioSesion();
    return sys->obtenerVideojuegosSus(nickname);
}

std::vector<DataVideojuego> UsuarioCtrl::obtenerVideojuegosNoSus() {
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string nickname = sys->getnicknameDeUsuarioQueInicioSesion();
    return sys->obtenerVideojuegosNoSus(nickname);
}

std::vector<std::string> UsuarioCtrl::obtenerVideojuegosDesarrollador() {
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string mail = sys->getmailDeUsuarioQueInicioSesion(); 
    Desarrollador* desarrollador = sys->obtenerDesarrolladorDesdeMail(mail);
    return desarrollador->getnombreDeVideojuegosDesarrollados();
}
 
std::vector<DataEstadistica> UsuarioCtrl::pedirEstadisticas(std::string nombreV) { //Seguro que es solo el nombre?? no cualquier cosa de la estadistica
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string mail = sys->getmailDeUsuarioQueInicioSesion(); 
    Desarrollador* desarrollador = sys->obtenerDesarrolladorDesdeMail(mail);
    Videojuego* videojuego = sys->obtenerVideojuegoDesdeNombre(nombreV);
    return desarrollador->obtenerEstadisticaParaVideojuegoConcreto(videojuego);
}

std::vector<DataPartida> UsuarioCtrl::obtenerPartidasIndFin() {
    SistemHandler* sys = SistemHandler::getInstancia();
    std::string nomb = sys->getnicknameDeUsuarioQueInicioSesion();
    return sys->obtenerPartidasIndividualesFinalizadas(nomb); 
}

void UsuarioCtrl::crearJugador(std::string mail, std::string contrasenia, std::string nickname, std::string descripcion){
    SistemHandler* sys = SistemHandler::getInstancia();
    Jugador* nuevo = new Jugador(mail, contrasenia, nickname, descripcion);
    sys->addJugador(nuevo);
}


void UsuarioCtrl::crearDesarrollador(std::string mail, std::string contrasenia, std::string empresa) {
    SistemHandler* sys = SistemHandler::getInstancia();
    Desarrollador* nuevo = new Desarrollador(mail, contrasenia, empresa);
    sys->addDesarrollador(nuevo);
}

Suscripcion* UsuarioCtrl::devuelveSiTieneSusActivaUsuarioQueInicioSesion(std::string videojuego, bool &res) {
    SistemHandler* sys = SistemHandler::getInstancia();
    Suscripcion* sus = nullptr;
    Jugador* j = sys->obtenerJugadorDesdeMail(sys->getmailDeUsuarioQueInicioSesion());
    res = j->tieneSuscripcionActiva(videojuego);
    if (res) {
        sus = j->suscripcionAVideojuego(videojuego);
    }
    return sus;
}

void UsuarioCtrl::crearPuntaje(int rating, std::string nick, std::string videojuego) {
    SistemHandler* sys = SistemHandler::getInstancia();
    Jugador* j = sys->obtenerJugadorDesdeMail(sys->getmailDeUsuarioQueInicioSesion());
    Videojuego* v = nullptr;
    v = sys->obtenerVideojuegoDesdeNombre(videojuego);
    if (v == nullptr) {
        throw std::invalid_argument("Nombre de videojuego incorrecto");  
    } 
    Puntos* nuevo = new Puntos(rating, j, v);
    j->agregarPuntaje(nuevo);
    v->agregarPuntaje(nuevo);
}

std::vector<DataPartidaMultijugador> UsuarioCtrl::obtenerPartidasMultiNoFinalizadas(std::string nick) {
    SistemHandler* sys = SistemHandler::getInstancia();
    Jugador* j = sys->obtenerJugadorDesdeMail(sys->getmailDeUsuarioQueInicioSesion());
    std::vector<Unidos*> unidos = j->getunidoAPartidasMultijuador();
    std::vector<DataPartidaMultijugador> res;
    for (int i=0; i< unidos.size(); i++) {
        res.insert(res.end(), unidos.at(i)->getPartida()->getDataPartidaMultijugador());
    }
    return res;
}

void UsuarioCtrl::salirPartidaMultijugador(int ident) {
    SistemHandler* sys = SistemHandler::getInstancia();
    TipoFechaHora fecha = sys->getFechaSistema();
    Jugador* j = sys->obtenerJugadorDesdeMail(sys->getmailDeUsuarioQueInicioSesion());
    std::vector<Unidos*> unidos = j->getunidoAPartidasMultijuador();
    int i = 0; 
    while (i < unidos.size() && unidos.at(i)->getPartida()->getident() != ident) { //excepcion si i== unidos.size
        i++;
    }
    if (i <= unidos.size()) {
        unidos.at(i)->setSalida(fecha);
        unidos.at(i)->setEsta(false);
    }
    else {
        throw std::invalid_argument("no estas unido a una partida multijugador con ese identificador");
    }
}

 int UsuarioCtrl::iniciarSesion(std::string mail, std::string contrasenia) {
    SistemHandler* sys = SistemHandler::getInstancia();
    int res = 0;
    if (sys->setteaSiExisteJugadorConMailYContrasenia(mail, contrasenia)) { //revisar
        res = 1;
        return res;
    }
    else if (sys->setteaSiExisteDesarrolladorConMailYContrasenia(mail, contrasenia)) {
        res = 2;
        return res;
    } 
    else {
        throw std::invalid_argument("No existe usuario con esos datos");
    }
 }

void UsuarioCtrl::agregarCategoria(std::string nombre, std::string descripcion, int tipoDeCat) {
    SistemHandler* sys = SistemHandler::getInstancia();
    Categoria* nueva = new Categoria(nombre, descripcion);
    if (tipoDeCat == 0) { // Plataforma 
        sys->addPlataforma(nueva);
    }
    else if (tipoDeCat == 1) { //Genero
        sys->addGenero(nueva);
    }
    else { //Otras Categorias
        sys->addOtrasCat(nueva);
    } 
}