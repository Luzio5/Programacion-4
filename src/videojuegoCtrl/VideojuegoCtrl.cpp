#include <videojuegoCtrl/VideojuegoCtrl.hpp>
#include <SistemHandler.hpp>

VideojuegoCtrl::VideojuegoCtrl() : tieneCategoria(false) {}

void VideojuegoCtrl::ingresarDatos(std::string nombre, std::string desc) {
    this->nombre = nombre;
    this->desc = desc;
}

void VideojuegoCtrl::ingresarCostosSuscripciones(int mensual, int trimestral, int anual, int vitalicia) {
    this->mensual = mensual;
    this->trimestral = trimestral;
    this->anual = anual;
    this->vitalicia = vitalicia;
}

std::vector<DataCategoria> VideojuegoCtrl::obtenerGenerosExistentes() {
    SistemHandler *s = SistemHandler::getInstancia();
    return s->getDataGeneros();
}

std::vector<DataCategoria> VideojuegoCtrl::obtenerPlataformasExistentes() {
    SistemHandler *s = SistemHandler::getInstancia();
    return s->getDataPlataformas();
}

std::vector<DataCategoria> VideojuegoCtrl::obtenerOtrasCatExistentes() {
    SistemHandler *s = SistemHandler::getInstancia();
    return s->getDataOtrasCat();
}

void VideojuegoCtrl::asignarGenero(std::string genero) {
    this->genero.push_back(genero);
}

void VideojuegoCtrl::asignarPlataforma(std::string plataforma) {
    this->plataforma.push_back(plataforma);
}

void VideojuegoCtrl::asignarCat(std::string cat) {
    this->categoria.push_back(cat);
    this->tieneCategoria = true;
}

DataVideojuego VideojuegoCtrl::obtenerDataVideojuegoAPublicar() {
    DataCosto dc(vitalicia, mensual, trimestral, anual);
    DataVideojuego dt(nombre, desc, "", 0.0, 0, categoria, plataforma, genero, dc, 0.0);
    return dt;
}

void VideojuegoCtrl::CancelarPublicacion() {
    this->tieneCategoria = false;
}

void VideojuegoCtrl::ConfirmarPublicacion() {
    SistemHandler *s = SistemHandler::getInstancia();
    Videojuego *v = new Videojuego();
    v->setNombre(this->nombre);
    v->setDescripcion(this->desc);
    std::vector<string>::iterator it;
    std::vector<string>::iterator fin = genero.end();
    for (it = genero.begin(); it != fin; advance(it,1)){
        v->addGenero(s->getGenero(*it));
    }
    fin = plataforma.end();
    for (it = plataforma.begin(); it != fin; advance(it,1)){
        v->addPlataforma(s->getPlataforma(*it));
    }
    fin = categoria.end();
    for (it = categoria.begin(); it != fin; advance(it,1)){
        v->addCategoria(s->getCategoria(*it));
    }
    v->setCostoAnual(this->anual);
    v->setCostoMensual(this->mensual);
    v->setCostoTrimestral(this->trimestral);
    Desarrollador* dev = s->obtenerDesarrolladorDesdeMail(s->getmailDeUsuarioQueInicioSesion());
    v->setempresa(dev->getempresa());
    s->obtenerDesarrolladorDesdeMail(s->getmailDeUsuarioQueInicioSesion())->agregarVideojuego(v);
    s->agregarVideojuego(v);
}

std::vector<std::string> VideojuegoCtrl::getgeneroenVcontroler() {
    return this->genero;      
}

std::vector<std::string> VideojuegoCtrl::getplataformaenVcontroler() {
    return this->plataforma; 
}

std::vector<std::string> VideojuegoCtrl::getotrasCatenVcontroler() {
    return this->categoria;
}

