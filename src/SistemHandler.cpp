#include <SistemHandler.hpp>
#include <iostream>


SistemHandler* SistemHandler::instancia = nullptr;

SistemHandler::SistemHandler()
    : fechaSistema(0,0,0,0,0)
    , nuevoident(0)
	, inicioSesion()
    , mailDeUsuarioQueInicioSesion("0")
    , nicknameDeUsuarioQueInicioSesion("0") //Si es desarrollador que quede con 0
    , empresaDeUsuarioQueInicioSesion("0") //Si es jugador que quede con 0
    , listaJugador()
    , listaDesarrollador()
    , listaVideojuego()
    , listaPartida()
{}

std::vector<DataVideojuego> SistemHandler::getlistaDeVideojuegos() {
    std::vector<DataVideojuego> res;
    for (int i=0; i< listaVideojuego.size(); i++) {
        res.insert(res.end(), listaVideojuego.at(i)->getDatos());
    }
    return res;    
}

SistemHandler* SistemHandler::getInstancia(){
    if (instancia == nullptr)
        instancia = new SistemHandler();
    return instancia;
}

void SistemHandler::addJugador(Jugador* jugador){
    listaJugador.push_back(jugador);
}

void SistemHandler::addDesarrollador(Desarrollador* jesarrollador){
    listaDesarrollador.push_back(jesarrollador);
}

void SistemHandler::agregarVideojuego(Videojuego* videojuego){
    listaVideojuego.push_back(videojuego);
}

void SistemHandler::agregarPartida(Partida* partida){
    listaPartida.push_back(partida);
}

Jugador* SistemHandler::obtenerJugadorDesdeMail(std::string mail){
    if (!listaJugador.empty()){
        vector<Jugador*>::iterator it = listaJugador.begin();
        vector<Jugador*>::iterator fin = listaJugador.end();
        while ((it != fin)&&((*it)->getmail() != mail)){
            std::advance(it,1); //esto en vez de it++ por si las posiciones no estan ordenadas
        }
        if (*it == nullptr) {
            return nullptr;
        }
        else if ((*it)->getmail() == mail){
            return (*it);
        }
        else {
            return nullptr; //No hay jugador con ese mail
        }
    }
    else {
        return nullptr; //No hay jugadores
    }
}       // Devuelve puntero al jugador de mail "mail" para poder trabajar

Desarrollador* SistemHandler::obtenerDesarrolladorDesdeMail(std::string mail){
    if (!listaDesarrollador.empty()){
        vector<Desarrollador*>::iterator it = listaDesarrollador.begin();
        vector<Desarrollador*>::iterator fin = listaDesarrollador.end();
        while ((it != fin)&&((*it)->getmail() != mail)){
            std::advance(it,1);
        }
        if (*it == nullptr) {
            return nullptr;
        }
        else if ((*it)->getmail() == mail){
            return (*it);
        }
        else {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
} // Devuelve puntero al desarrollador de mail "mail" para poder trabajar

Partida* SistemHandler::obtenerPartidaDesdeIdent(int identificador){
    if (!listaPartida.empty()){
        vector<Partida*>::iterator it = listaPartida.begin();
        vector<Partida*>::iterator fin = listaPartida.end();
        while ((it != fin)&&((*it)->getident() != identificador)){
            std::advance(it,1);
        }
        if (*it == nullptr) {
            return nullptr;
        }
        else if ((*it)->getident() == identificador){
            return (*it);
        }
        else {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
} // Devuelve puntero a la partida con identificador = ident

Videojuego* SistemHandler::obtenerVideojuegoDesdeNombre(std::string nombreDeVideojuego){
    if (!listaVideojuego.empty()){
        vector<Videojuego*>::iterator it = listaVideojuego.begin();
        vector<Videojuego*>::iterator fin = listaVideojuego.end();
        while ((it != fin)&&((*it)->getNombre() != nombreDeVideojuego)){
            std::advance(it,1);
        }
        if (*it == nullptr) {
            return nullptr;
        }
        else if ((*it)->getNombre() == nombreDeVideojuego){
            return (*it);
        }
        else {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
} //  Devuelve puntero al videojuego de nombre = nombreDeVideojuego

Usuario* SistemHandler::getUsuarioSesionActual(){
    return inicioSesion;
}

Jugador* SistemHandler::getJugadorSesionActual(){
    return nullptr; //que devuelvo?
}

std::vector<DataVideojuego> SistemHandler::obtenerVideojuegosSus(std::string nomJ){
//Es precondicion que haya al menos un jugador.
    vector<Jugador*>::iterator it = listaJugador.begin();
    vector<Jugador*>::iterator fin = listaJugador.end();
    while ((it != fin)&&((*it)->getnickname() != nomJ)){
        std::advance(it,1);
    }
    if (*it == nullptr) {
        return std::vector<DataVideojuego>(); //No hay jugador con ese mail
    }
    else if ((*it)->getnickname() == nomJ){
        return (*it)->obtenerVideojuegosSus();
    }
    else {
        return std::vector<DataVideojuego>(); //No hay jugador con ese mail
    }
}

std::vector<DataVideojuego> SistemHandler::obtenerVideojuegosNoSus(std::string nomJ){
    if (!listaVideojuego.empty()){
        std::vector<DataVideojuego> ret;
        vector<Videojuego*>::iterator it = listaVideojuego.begin();
        int tamanio = listaVideojuego.size();
        for(int i = 0; i<tamanio; i++, std::advance(it,1)){ //FALTA EL ULTIMO
            if ((*it)->noSubscrito(nomJ)) {
                DataVideojuego a = (*it)->getDatos();
                ret.push_back(a);
            }
        }
        return ret;
    }
    else {
        return std::vector<DataVideojuego>();
    }
}

bool SistemHandler::existeVideojuego(std::string NombreVideojuego){
    if (!listaVideojuego.empty()){
        vector<Videojuego*>::iterator it = listaVideojuego.begin();
        vector<Videojuego*>::iterator fin = listaVideojuego.end();
        while ((it != fin)&&((*it)->getNombre() != NombreVideojuego)) {
            std::advance(it,1);
        }
        if (*it == nullptr) {
            return false;
        }
        else if ((*it)->getNombre() == NombreVideojuego){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void SistemHandler::cancelarSubscripcionActual(std::string j, std::string v){ //habria error si no hay jugadores
    vector<Jugador*>::iterator it = listaJugador.begin();
    vector<Jugador*>::iterator fin = listaJugador.end();
    while ((it != fin)&&((*it)->getnickname() != j)){
        std::advance(it,1);
    }
    if (*it == nullptr) {
         //No hay jugador con ese nombre
    }
    else if ((*it)->getnickname() == j){
        (*it)->cancelarSuscripcionAVideojuego(v);
    }
    else {
        //No hay jugador con ese nombre
    }
}

void SistemHandler::asociarSusJ(Suscripcion* s, std::string j){ //habria error si no hay jugadores
    vector<Jugador*>::iterator it = listaJugador.begin();
    vector<Jugador*>::iterator fin = listaJugador.end();
    while ((it != fin)&&((*it)->getnickname() != j)){
        std::advance(it,1);
    }
    if (*it == nullptr) {
        //No hay jugador con ese nombre
    }
    else if ((*it)->getnickname() == j){
        (*it)->linkearSuscripcionAJugador(s);
    }
    else {
        //No hay jugador con ese nombre
    }
}

void SistemHandler::asociarSusV(Suscripcion* s, std::string v){
    vector<Videojuego*>::iterator it = listaVideojuego.begin();
    vector<Videojuego*>::iterator fin = listaVideojuego.end();
    while ((it != fin)&&((*it)->getNombre() != v)) {
        std::advance(it,1);
    }
    if (*it == nullptr) {
        //No hay jugador con ese nombre
    }
    else if ((*it)->getNombre() == v){
        (*it)->linkearVideojuegoASubscripcion(s);
    }
    else {
        //No existe ese videojuego
    }
}

std::vector<DataPartida> SistemHandler::obtenerPartidasIndividualesFinalizadas(std::string nomJ){ //habria error si no hay jugadores
    vector<Jugador*>::iterator it = listaJugador.begin();
    vector<Jugador*>::iterator fin = listaJugador.end();
    while ((it != fin)&&((*it)->getnickname() != nomJ)){
        std::advance(it,1);
    }
    if (*it == nullptr) {
        return std::vector<DataPartida>();//No hay jugador con ese nombre
    }
    else if ((*it)->getnickname() == nomJ){
        return (*it)->obtenerPartidasIndFin();
    }
    else {
        return std::vector<DataPartida>();//No hay jugador con ese nombre
    }
}

bool SistemHandler::existePartidaConIdentificador(int ident){
    if (!listaPartida.empty()){
        vector<Partida*>::iterator it = listaPartida.begin();
        vector<Partida*>::iterator fin = listaPartida.end();
        while ((it != fin)&&((*it)->getident() != ident)){
            std::advance(it,1);
        }
        if (*it == nullptr) {
            return false;
        }
        else if ((*it)->getident() == ident){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int SistemHandler::getIdentNuevo(){
    int a = nuevoident++;
    return a;
}

std::vector<std::string> SistemHandler::jugadoresConSusActiva(std::string VideojuegoNombre){
    std::vector<Videojuego*>::iterator it = listaVideojuego.begin();
    std::vector<Videojuego*>::iterator fin = listaVideojuego.end();
    while ((it != fin)&&((*it)->getNombre() != VideojuegoNombre)) {
        std::advance(it,1);
    }
    if (*it == nullptr) {
        return std::vector<std::string>();//No existe ese videojuego
    }
    else if ((*it)->getNombre() == VideojuegoNombre){
        std::vector<Jugador*> j = (*it)->jugadoresConSubscripcionActiva();
        std::vector<std::string> s;
        for(std::vector<Jugador*>::iterator itj = j.begin(); itj != j.end(); advance(itj,1)){
            s.push_back((*itj)->getnickname());
        }
        return s;
    }
    else {
        return std::vector<std::string>();//No existe ese videojuego
    }
}

/*void SistemHandler::asociarParJ(Partida* p, std::string j){ Se hace al crear la partida
    vector<Jugador*>::iterator it = listaJugador.begin();
    vector<Jugador*>::iterator fin = listaJugador.end();
    while ((it != fin)&&((*it)->getnickname() != j)){
        std::advance(it,1);
    }
    if ((*it)->getnickname() == j){
        (*it)->agregarInicio(p);
    }
    else {
        //No hay jugador con ese nombre
    }
}

void SistemHandler::asociarParV(Partida* p, std::string v){} */


void SistemHandler::asociarParJs(PartidaMultijugador* p, std::vector<std::string> jugadores){
    vector<string>::iterator fin = jugadores.end();
    vector<string>::iterator it = jugadores.begin();
    vector<Jugador*>::iterator jug;
    vector<Jugador*>::iterator ult;
    vector<Unidos*> unidos;
    Unidos * creador;
    int tamanio = jugadores.size();
    for(int i = 1; i<=tamanio; i++, std::advance(it,1)){
        jug = listaJugador.begin();
        ult = listaJugador.end();
        while ((jug != ult)&&((*jug)->getnickname() != (*it))){
            std::advance(jug,1); //esto en vez de it++ por si las posiciones no estan ordenadas
        }
        if (*jug == nullptr) { ////////////////////////////////Facundo
            //Error en el nombre de un jugador //////////////// No estamos seguros de q esto este del todo bien
        } ////////////////////////////////////////////////////Luciano
        else if ((*jug)->getnickname() == (*it)){
            creador = new Unidos((*jug),p);
            unidos.push_back(creador);
            (*jug)->agregarUnidoAPartidaM(creador);
        }
        else {
            //Error en el nombre de un jugador
        }
    }
    p->setUnidos(unidos);
}

void SistemHandler::continuarPartidaIndividual(int ident){
    if (!listaPartida.empty()){
        vector<Partida*>::iterator it = listaPartida.begin();
        vector<Partida*>::iterator fin = listaPartida.end();
        while ((it != fin)&&((*it)->getident() != ident)){
            std::advance(it,1);
        }
        if (*it == nullptr) {
          ////identificador incorrecto
        }
        else if ((*it)->getident() == ident){
            (*it)->setcontinuaAnterior(true);
        }
        else {
            //identificador incorrecto
        }
    }
    else {
        //no hay partidas
    }
}

std::vector<DataCategoria> SistemHandler::getDataGeneros(){
    vector<DataCategoria> ret;
    vector<Categoria*>::iterator it = listaGenero.begin();
    int tamanio = listaGenero.size();
    for(int i = 1; i <= tamanio; i++, std::advance(it,1)){
        ret.push_back((*it)->getData());
    }
    return ret;
}

std::vector<DataCategoria> SistemHandler::getDataPlataformas(){
    vector<DataCategoria> ret;
    vector<Categoria*>::iterator it = listaPlataforma.begin();
    int tamanio = listaPlataforma.size();
    for(int i = 1; i <= tamanio; i++, std::advance(it,1)){
        ret.push_back((*it)->getData());
    }
    return ret;
}

std::vector<DataCategoria> SistemHandler::getDataOtrasCat(){
    vector<DataCategoria> ret;
    vector<Categoria*>::iterator it = listaOtrasCat.begin();
    int tamanio = listaOtrasCat.size();
    for(int i = 1; i <= tamanio; i++, std::advance(it,1)){
        ret.push_back((*it)->getData());
    }
    return ret;
}

int SistemHandler::getJugadoresConSuscripcion(std::string nombrejuego){
    int ret = 0;
    vector<Jugador*>::iterator it = listaJugador.begin();
    int tamanio = listaJugador.size();
    for(int i = 1; i <= tamanio; i++, std::advance(it,1)){
        if ((*it)->tieneSuscricpion(nombrejuego))
            ret++;
    }
    return ret;
}

void SistemHandler::setFechaSistema(TipoFechaHora fecha){
    fechaSistema = fecha;
    for(int i = 0; i < listaSusTemporales.size(); i++){
        listaSusTemporales.at(i)->setearActividad(fecha);
    }
}

TipoFechaHora SistemHandler::getFechaSistema() const{
    return fechaSistema;
}

std::string SistemHandler::getmailDeUsuarioQueInicioSesion(){
    return mailDeUsuarioQueInicioSesion;
}

std::string SistemHandler::getnicknameDeUsuarioQueInicioSesion(){
    return nicknameDeUsuarioQueInicioSesion;
}

std::string SistemHandler::getempresaDeUsuarioQueInicioSesion(){
    return empresaDeUsuarioQueInicioSesion;
}

void SistemHandler::setmailDeUsuarioQueInicioSesion(std::string mail){
    mailDeUsuarioQueInicioSesion = mail;
}

void SistemHandler::setnicknameDeUsuarioQueInicioSesion(std::string nickname){
    nicknameDeUsuarioQueInicioSesion = nickname;
}

void SistemHandler::setempresaDeUsuarioQueInicioSesion(std::string empresa){
    empresaDeUsuarioQueInicioSesion = empresa;
}

bool SistemHandler::setteaSiExisteJugadorConMailYContrasenia(std::string mail,std::string contrasenia) { // Si existe el jugador, devuelve true y settea el nick, mail del jugador y la empresa = 0. NECESARIO PARA CASO DE USO INICIAR SESION
    Jugador* jug = nullptr;
    jug = this->obtenerJugadorDesdeMail(mail);
    bool res = false;
    if (jug != nullptr) {
        if (jug->getcontrasenia().compare(contrasenia) == 0) {
            res = true;
            std::string nick = jug->getnickname();
            std::string empresa = "0";
            this->setmailDeUsuarioQueInicioSesion(mail);
            this->setnicknameDeUsuarioQueInicioSesion(nick);
            this->setempresaDeUsuarioQueInicioSesion(empresa);
        }
    }
    return res;
}

bool SistemHandler::setteaSiExisteDesarrolladorConMailYContrasenia(std::string mail,std::string contrasenia) { // Si existe el desarrollador, devuelve true y settea la empresa, mail del desarrollador y el nick = 0. NECESARIO PARA CASO DE USO INICIAR SESION
    Desarrollador* des = nullptr;
    des = this->obtenerDesarrolladorDesdeMail(mail);
    bool res = false;
    if (des != nullptr) {
        if (des->getcontrasenia().compare(contrasenia) == 0) {
            res = true;
            std::string nick = "0";
            std::string empresa = des->getempresa();
            this->setmailDeUsuarioQueInicioSesion(mail);
            this->setnicknameDeUsuarioQueInicioSesion(nick);
            this->setempresaDeUsuarioQueInicioSesion(empresa);
        }
    }
    return res;
}

bool SistemHandler::existeJugadorConNickname(std::string nickname){
    if (!listaJugador.empty()){
        vector<Jugador*>::iterator it = listaJugador.begin();
        vector<Jugador*>::iterator fin = listaJugador.end();
        while ((it != fin)&&((*it)->getnickname() != nickname)){
            std::advance(it,1); //esto en vez de it++ por si las posiciones no estan ordenadas
        }
        if (*it == nullptr) {
            return false;
        }
        else if ((*it)->getnickname() == nickname){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
} // NECESARIO PARA CASO DE USO ALTA DE USUARIO

bool SistemHandler::existeDesarrolladorConMail(std::string mail){
    if (!listaDesarrollador.empty()){
        vector<Desarrollador*>::iterator it = listaDesarrollador.begin();
        vector<Desarrollador*>::iterator fin = listaDesarrollador.end();
        while ((it != fin)&&((*it)->getmail() != mail)){
            std::advance(it,1); //esto en vez de it++ por si las posiciones no estan ordenadas
        }
        if (*it == nullptr) {
            return false;
        }
        else if ((*it)->getmail() == mail){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
} // PUEDE QUE NO SEA NECESARIA PARA NADA

Estadistica* SistemHandler::getEstadistica(std::string nombre){
    std::vector<Estadistica*>::iterator it = listaEstadistica.begin();
    std::vector<Estadistica*>::iterator fin = listaEstadistica.end();
    while ((it != fin)&&((*it)->getNombre()!=nombre)){
        advance(it,1);
    }
    if (*it == nullptr) {
        return nullptr;
    }
    else if ((*it)->getNombre()==nombre){
        return *it;
    }
    else {
        return nullptr;
    }
}

void SistemHandler::inicializarEstadisticas(){
    Metodo* metHorasJug = new MetodoHorasJugadas();
    Metodo* metPopularidad = new MetodoPopularidad();
    Metodo* metSuscripcionesTotales = new MetodoSuscripcionesTotales();
    Estadistica* HorasJugadas = new Estadistica("Horas Jugadas","Calcula la cantidad total de horas jugadas de un videojuego", metHorasJug);
    Estadistica* Popularidad = new Estadistica("Popularidad","Calcula la popularidad de un videojuego", metPopularidad);
    Estadistica* SuscripcionesTotales = new Estadistica("Suscripciones Totales","Calcula la cantidad total de suscripciones de un videojuego", metSuscripcionesTotales);
    listaEstadistica.push_back(HorasJugadas);
    listaEstadistica.push_back(Popularidad);
    listaEstadistica.push_back(SuscripcionesTotales);
}


void SistemHandler::addGenero(Categoria* categoria){
    this->listaGenero.push_back(categoria);
}

void SistemHandler::addPlataforma(Categoria* categoria){
    this->listaPlataforma.push_back(categoria);
}

void SistemHandler::addOtrasCat(Categoria* categoria){
    this->listaOtrasCat.push_back(categoria);
}

std::vector<std::string> SistemHandler::obtenerVideojuegos(){
    Desarrollador * dev = obtenerDesarrolladorDesdeMail(getmailDeUsuarioQueInicioSesion()); //suponiendo que el usuario que inicio sesion es el desrrollador
    std::vector<Videojuego*> juegos = dev->getvideojuegos();
    std::vector<Videojuego*>::iterator fin = juegos.end();
    std::vector<std::string> ret;
    for(std::vector<Videojuego*>::iterator it = juegos.begin(); it != fin; advance(it,1)){
        if (!(*it)->tienePartidaActiva()){
            ret.push_back((*it)->getNombre());
        }
    }
    return ret;
}

void SistemHandler::confirmarEliminarVideojuego(std::string nombre){
    Videojuego* v = obtenerVideojuegoDesdeNombre(nombre);
    int s = 0;
    for (std::vector<Jugador*>::iterator it = listaJugador.begin(); it != listaJugador.end(); it++){ //recorrer usuarios
        std::vector<Suscripcion*> sus = (*it)->getsuscripciones();
        for (std::vector<Suscripcion*>::iterator itsus = sus.begin(); itsus != sus.end(); itsus++){
            if((*itsus)->getVideojuegoAsociado() == v){
                delete (*itsus);
                sus.erase(itsus);
                (*it)->setsuscripciones(sus);
            }
        } 
    v->eliminarVideojuego();
    std::vector<Videojuego*>::iterator itv = listaVideojuego.begin();
    while (s < listaVideojuego.size() && listaVideojuego.at(s) != v) {
        s++;
        advance(itv,1);
    }
    if (s < listaVideojuego.size()){
        delete v;
        listaVideojuego.erase(itv);
    }
}
}

Categoria* SistemHandler::getCategoria(std::string nombre){
    std::vector<Categoria*>::iterator it = listaOtrasCat.begin();
    std::vector<Categoria*>::iterator fin = listaOtrasCat.end();
    while ((it != fin)&&((*it)->getNombre()!=nombre))
        advance(it,1);
    if (it!=fin){
        return (*it);
    }
    else {
        return nullptr;
    }
}

Categoria* SistemHandler::getGenero(std::string nombre){
    std::vector<Categoria*>::iterator it = listaGenero.begin();
    std::vector<Categoria*>::iterator fin = listaGenero.end();
    while ((it != fin)&&((*it)->getNombre()!=nombre))
        advance(it,1);
    if (it!=fin){
        return (*it);
    }
    else {
        return nullptr;
    }
}

Categoria* SistemHandler::getPlataforma(std::string nombre){
    std::vector<Categoria*>::iterator it = listaPlataforma.begin();
    std::vector<Categoria*>::iterator fin = listaPlataforma.end();
    while ((it != fin)&&((*it)->getNombre()!=nombre))
        advance(it,1);
    if (it!=fin){
        return (*it);
    }
    else {
        return nullptr;
    }
}

void SistemHandler::agregarSuscripcion(Temporal* sus){
    listaSusTemporales.push_back(sus);
}

std::vector<Desarrollador*> SistemHandler::getDesarrolladores() {
    return listaDesarrollador;
}

std::vector<Jugador*> SistemHandler::getJugadores() {
    return listaJugador;
}

std::vector<Videojuego*> SistemHandler::getVideojuegos() {
    return listaVideojuego;    
}

std::vector<Partida*> SistemHandler::getPartidas() {
    return listaPartida;
}

std::vector<Categoria*> SistemHandler::getGeneros() {
    return listaGenero;    
}

std::vector<Categoria*> SistemHandler::getPlataforma() {
    return listaPlataforma;    
}

std::vector<Categoria*> SistemHandler::getOtrasCategorias() {
    return listaOtrasCat;    
}

std::vector<Estadistica*> SistemHandler::getEstadisticas() {
    return listaEstadistica;    
}