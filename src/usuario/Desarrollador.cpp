#include <usuario/Desarrollador.hpp>
#include <stdexcept>
         
Desarrollador::Desarrollador(std::string mail, std::string contrasenia, std::string empresa)
: Usuario(mail, contrasenia)
, empresa(empresa) {
   std::vector<Categoria*> categoriasCreadas;
   std::vector<Estadistica*> estadisticasSeleccionadas;
   std::vector<Videojuego*> videojuegosCreados;
   this->categoriasCreadas = categoriasCreadas;
   this->estadisticasSeleccionadas = estadisticasSeleccionadas;
   this->videojuegosCreados = videojuegosCreados;
}

std::string Desarrollador::getempresa() {
    return this->empresa;
}

std::vector<Estadistica*> Desarrollador::getestadisticas() {
    return this->estadisticasSeleccionadas;
}

std::vector<Categoria*> Desarrollador::getcategoriasCreadas() {
    return this->categoriasCreadas; 
}

vector<Videojuego*> Desarrollador::getvideojuegos() {
    return this->videojuegosCreados;
}

void Desarrollador::setempresa(std::string empresa) {
    this->empresa = empresa;
}

void Desarrollador::setcategoriasCreadas(std::vector<Categoria*> categoriasCreadas) {
    this->categoriasCreadas = categoriasCreadas;
}

void Desarrollador::setestadisticasSeleccionadas(std::vector<Estadistica*> estadisticasSeleccionadas) {
    this->estadisticasSeleccionadas = estadisticasSeleccionadas;
}

void Desarrollador::setvideojuegosCreados(std::vector<Videojuego*> videojuegosCreados) {
    this->videojuegosCreados = videojuegosCreados;
}

void Desarrollador::agergarCategoria(Categoria* categoria) {
    std::vector<Categoria*> categoriasCreadas = this->getcategoriasCreadas();
    categoriasCreadas.insert(categoriasCreadas.end(), categoria);
    this->setcategoriasCreadas(categoriasCreadas);
}

void Desarrollador::agergarEstadistica(Estadistica* estadistica) {
    std::vector<Estadistica*> estadisticaCreadas = this->getestadisticas();
    estadisticaCreadas.insert(estadisticaCreadas.end(), estadistica);
    this->setestadisticasSeleccionadas(estadisticaCreadas);
}

void Desarrollador::agregarVideojuego(Videojuego* juego) {
    std::vector<Videojuego*> VideojuegoCreados = this->getvideojuegos();
    VideojuegoCreados.insert(VideojuegoCreados.end(), juego);
    this->setvideojuegosCreados(VideojuegoCreados);
}

std::vector<DataEstadistica> Desarrollador::obtenerEstadisticaParaVideojuegoConcreto(Videojuego* Videojuego) {
    std::vector<Estadistica*> vectorEstadisticas = getestadisticas();
    std::vector<DataEstadistica> res;
    for (int i=0; i< vectorEstadisticas.size(); i++){
        DataEstadistica data(vectorEstadisticas.at(i)->getNombre(),  vectorEstadisticas.at(i)->getValor(Videojuego)); 
        res.insert(res.end(), data);
    }
    return res;
}

std::vector<std::string> Desarrollador::getnombreDeVideojuegosDesarrollados() {
    std::vector<std::string> res;
    std::vector<Videojuego*> VectorVideojuegos = getvideojuegos();
    for (int i=0; i< VectorVideojuegos.size(); i++){
       res.insert(res.end(), VectorVideojuegos.at(i)->getNombre());        
    }
    return res;
} 

std::vector<DataPartida> Desarrollador::obtenerPartidasActuales() {
    throw std::logic_error("obtenerPArtidasActuales desde Desarrollador");
}