#include <iostream>
#include <string>
#include <SistemHandler.hpp>
#include <Fabrica.hpp>
#include <data/MetodoPago.hpp>
#include <data/DataCosto.hpp>

#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

IUsuario* Ucontroler;
IPartida* Pcontroler;
ISuscribirse* Scontroler;
IVideojuego* Vcontroler;

void menu(std::istream&, std::ostream&);
void caso_2_desarrollador(std::istream&, std::ostream&);
void caso_2_jugador(std::istream&, std::ostream&);
void caso_3(std::istream&, std::ostream&);

int main() {
  menu(std::cin, std::cout);
}

void menu(std::istream& cin, std::ostream& cout) {
  Fabrica fabrica;
  Ucontroler = fabrica.createIUsuario();
  Pcontroler = fabrica.createIPartida();
  Scontroler = fabrica.createISuscribirse();
  Vcontroler = fabrica.createIVideojuego();
  int opcion = 4;

  do {
    cout << "Ingrese opción (1-Alta de Usuario, 2-Iniciar Sesión, 3-Cargar datos de prueba, 4- Salir)" << endl;
    cin >> opcion;
    switch(opcion) {
      case 5: break;
      case 1: { //alta de Usuario
          std::string mail;
          std::string contrasenia;
          int tipo;
          cout << "Ingrese mail" <<endl;
          cin >> mail;
          cout << "Ingrese contraseña" <<endl;
          std::getline(std::cin >> std::ws, contrasenia);
          cout << "Jugador (1); Desarrollador(0)" <<endl;
          cin >> tipo;
          if (tipo == 1) { // JUGADOR
            std::string nick;
            std::string descripcion;
            cout << "Ingrese Nickname" <<endl;
            cin >> nick;
            cout << "Ingrese Descripcion" <<endl;
            std::getline(std::cin >> std::ws, descripcion);
            SistemHandler* sys = SistemHandler::getInstancia();
            int cancelar = 0;
            while (sys->existeJugadorConNickname(nick) && cancelar == 0) {
              cout << "Nickname ya usado" <<endl;
              cout << "¿Desea cancelar el alta de usuario? (1 si; 0 no (será pedido nuevo nick))" << endl;
              cin >> cancelar;
              if (cancelar == 0) {
                cout << "Ingrese otro Nickname" <<endl;
                cin >> nick;
              }
            }
            if (cancelar == 0) { // Nickname Correcto
              int correcto;
              cout << "Nickname correcto" <<endl;
              cout << "¿Desea confirmar el alta de usuario? (1 si; 0 no)" <<endl;
              cin >> correcto;
              if (correcto == 1) {
                Ucontroler->crearJugador(mail, contrasenia, nick, descripcion);
              }
            }
          }
          else if (tipo == 0) { // DESARROLLADOR
            std::string empresa;
            int correcto;
            cout << "Ingrese Empresa" <<endl;
            std::getline(std::cin >> std::ws, empresa);
            cout << "¿Desea confirmar el alta de usuario? (1 si; 0 no)" <<endl;
            cin >> correcto;
            if (correcto == 1) {
              Ucontroler->crearDesarrollador(mail, contrasenia, empresa);
            }
          }
          else { //ingreso numero mal, ni cero ni uno
            cout << "Numero equivocado" <<endl;
          }
        break;
      }
      case 2: { //iniciar sesion
        std::string mail;
        std::string contrasenia;
        cout << "Ingrese mail" <<endl;
        cin >> mail;
        cout << "Ingrese contraseña" <<endl;
        std::getline(std::cin >> std::ws, contrasenia);
        int i = 0;
        try {
          i = Ucontroler->iniciarSesion(mail, contrasenia);
        }
        catch (std::invalid_argument& e) {
          cout << e.what() <<endl;
          break;
        }
        if (i == 1) {
          caso_2_jugador(cin, cout);
        }
        else if (i == 2) {
          caso_2_desarrollador(cin, cout);
        }
        break;
      }
      case 3: {
        caso_3(cin, cout);
        cout << "Datos cargados" <<endl;
        break;
      }
    }
  }
  while(opcion != 4);
}


void caso_2_desarrollador (std::istream& cin, std::ostream& cout) {

  int opcion = 8;

  do {
    cout << "Ingrese opción (1: Agregar categoría, 2: Publicar videojuego, 3: Eliminar videojuego, 4: Seleccionar estadísticas, 5: Consultar estadísticas, 6: Ver info de videojuego, 7: Modificar fecha del sistema, 8: Salir)" << endl;
    cin >> opcion;

    switch (opcion) {
      case 8: break;
      case 1: { //Agregar categoría
        SistemHandler* sys = SistemHandler::getInstancia();
        std::vector<DataCategoria> generos = sys->getDataGeneros();
        std::vector<DataCategoria> plataformas = sys->getDataPlataformas();
        std::vector<DataCategoria> otrascats = sys->getDataOtrasCat();
        cout << "Generos existentes : " << endl;
        for (int i=0; i < generos.size(); i++) {
          cout << generos.at(i).getNombre() << endl;
        }
        cout << "Plataformas existentes : " << endl;
        for (int i=0; i < plataformas.size(); i++) {
          cout << plataformas.at(i).getNombre() << endl;
        }
        cout << "Otras categorias existentes : " << endl;
          for (int i=0; i < otrascats.size(); i++) {
          cout << otrascats.at(i).getNombre() << endl;
        }
        cout << "Ingrese tipo de la nueva categoria (0-Plataforma; 1-Genero; 2-Otras Categorias )" << endl;
        int i;
        cin >> i;
        cout << "Ingrese nombre de nueva categoria " << endl;
        std::string nombre;
        std::getline(std::cin >> std::ws, nombre);
        cout << "Ingrese descripción " << endl;
        std::string descripcion;
        std::getline(std::cin >> std::ws, descripcion);
        Ucontroler->agregarCategoria(nombre, descripcion, i);
        cout << "Categoria ingresada con exito" << endl;
        break;
      }
      case 2: { //Publicar videojuego
        cout << "Ingrese un nombre:" << endl;
        string nombre;
        std::getline(std::cin >> std::ws, nombre);
        cout << "Ingrese una descripcion:" << endl;
        string descripcion;
        std::getline(std::cin >> std::ws, descripcion);
        Vcontroler->ingresarDatos(nombre, descripcion);
        int mensual, trimestral, anual, vitalicia;
        cout << "Ingrese el costo de la suscripcion mensual:" << endl;
        cin >> mensual;
        cout << "Ingrese el costo de la suscripcion trimestral:" << endl;
        cin >> trimestral;
        cout << "Ingrese el costo de la suscripcion anual:" << endl;
        cin >> anual;
        cout << "Ingrese el costo de la suscripcion vitalicia:" << endl;
        cin >> vitalicia;
        Vcontroler->ingresarCostosSuscripciones(mensual, trimestral, anual, vitalicia);
        std::vector<DataCategoria> generos = Vcontroler->obtenerGenerosExistentes();
        std::vector<DataCategoria> plataformas = Vcontroler->obtenerPlataformasExistentes();
        std::vector<DataCategoria> otrasCat = Vcontroler->obtenerOtrasCatExistentes();
        string lector;
        cout << "Ingresar los generos que quiera, cuando haya terminado ingresa 0." << endl;
        for (int i=0; i < generos.size(); i++) {
          cout << generos.at(i).getNombre() << ": " << generos.at(i).getDesc()<< endl;
        }
        std::getline(std::cin >> std::ws, lector);
        while (lector != "0"){
          Vcontroler->asignarGenero(lector);
          std::getline(std::cin >> std::ws, lector);
        }
        cout << "Ingresar las plataformas que quiera, cuando haya terminado ingresa 0." << endl;
        for (int i=0; i < plataformas.size(); i++) {
          cout << plataformas.at(i).getNombre() << ": " << plataformas.at(i).getDesc() << endl;
        }
        std::getline(std::cin >> std::ws, lector);//luciano
        while (lector != "0"){
          Vcontroler->asignarPlataforma(lector);
          std::getline(std::cin >> std::ws, lector);
        }
        cout << "Ingresar las otras categorias que quiera, cuando haya terminado ingresa 0." << endl;
        for (int i=0; i < otrasCat.size(); i++) {
          cout << otrasCat.at(i).getNombre() << ": " << otrasCat.at(i).getDesc() << endl;
        }
        std::getline(std::cin >> std::ws, lector);
        while (lector != "0"){
          Vcontroler->asignarCat(lector);
          std::getline(std::cin >> std::ws, lector);
        }
        cout << "Verifique si esta todo bien antes de confirmar la publicacion." << endl;
        DataVideojuego data = Vcontroler->obtenerDataVideojuegoAPublicar();
        cout << "Nombre: " << data.getNombre() << endl << "Descricpcion: " << data.getDescripcion() << endl << "Costos: " << endl << "Mensual: " << data.getCosto().getCostoTemporal1mes() << endl << "Trimestral: " << data.getCosto().getCostoTemporal3mes() << endl << "Anual: " << data.getCosto().getCostoTemporal12mes() << endl << "Vitalicia: " << data.getCosto().getCostoVitalicia() << endl;
        std::vector<std::string> datacategorias = data.getOtrasCategorias();
        std::vector<std::string> dataplataformas = data.getPlataformas();
        std::vector<std::string> datageneros = data.getGeneros();
        cout << "Generos:" << endl;
        for (int i = 0; i < datageneros.size(); i++){ //vector de strings
          cout << datageneros.at(i) << endl;
        }
        cout << "Plataformas:" << endl;
        for (int i = 0; i < dataplataformas.size(); i++){ //vector de strings
          cout << dataplataformas.at(i) << endl;
        }
        cout << "Otras categorias:" << endl;
        for (int i = 0; i < datacategorias.size(); i++){ //vector de strings
          cout << datacategorias.at(i) << endl;
        }
        cout << "Ingrese 1 si desea confirmar la publicacion, o 0 en caso contrario." << endl;
        bool respuesta;
        cin >> respuesta;
        if (respuesta){
          Vcontroler->ConfirmarPublicacion();//esto
        }
        else {
          Vcontroler->CancelarPublicacion();
        }
        break;
      }
      case 3: { //Eliminar videojuego
        SistemHandler * sys = SistemHandler::getInstancia();
        std::vector<std::string> juegos = sys->obtenerVideojuegos();
        for (int i = 0; i < juegos.size(); i++){ //imprime juegos del dev
          cout << juegos.at(i) << endl;
        }
        cout << "Ingrese el nombre del Videojuego que desdea eliminar: " << endl;
        std::string nombrev;
        std::getline(std::cin >> std::ws, nombrev);
        cout << "Los datos no podran recuperarse. Si desde confirmar la eliminacion digite 1, de lo contrario 0. " << endl;
        int decision;
        cin >> decision;
        if (decision==1){
          sys->confirmarEliminarVideojuego(nombrev);
        }
        break;
      }
      case 4: { //Seleccionar estadísticas
        bool a,b,c;
        cout << "Ingrese 1 si desea agregar la estadistica Popularidad, o 0 en caso contrario." << endl;
        cin >> a;
        cout << "Ingrese 1 si desea agregar la estadistica Horas Jugadas, o 0 en caso contrario." << endl;
        cin >> b;
        cout << "Ingrese 1 si desea agregar la estadistica Suscripciones Totales, o 0 en caso contrario." << endl;
        cin >> c;
        std::vector<Estadistica*> esta;
        SistemHandler* sys = SistemHandler::getInstancia();
        if (a){
          esta.push_back(sys->getEstadistica("Popularidad"));
        }
        if(b){
          esta.push_back(sys->getEstadistica("Horas Jugadas"));
        }
        if (c){
          esta.push_back(sys->getEstadistica("Suscripciones Totales"));
        }
        std::string mail = sys->getmailDeUsuarioQueInicioSesion();
        Desarrollador * dev = sys->obtenerDesarrolladorDesdeMail(mail);
        dev->setestadisticasSeleccionadas(esta);
        break;
      }
      case 5: { //Consultar estadísticas
        cout << "Selecciones el videojuego del que quiere ver estadisticas." <<endl;
        std::vector<std::string> juegos = Ucontroler->obtenerVideojuegosDesarrollador();
        string juego;
        std::getline(std::cin >> std::ws, juego);
        std::vector<DataEstadistica> estadisticas = Ucontroler->pedirEstadisticas(juego);
        for (int i=0; i< estadisticas.size(); i++) {
          cout << estadisticas.at(i).getnombre() << ":" << estadisticas.at(i).getvalor() << endl;
        }
        break;
      }
      case 6: { //Ver info de videojuego
        SistemHandler* sys = SistemHandler::getInstancia();
        std::string nombreV;
        std::vector<DataVideojuego> lista_juegos = sys->getlistaDeVideojuegos();
        cout << "Los videojuegos que hay en el sistema son: " << endl;
        for (int i=0; i< lista_juegos.size(); i++) {
          cout << lista_juegos.at(i).getNombre() << endl;
        }
        cout << "Ingrese nombre del videojuego a mostrar info" <<endl;
        std::getline(std::cin >> std::ws, nombreV);
        if (!sys->existeVideojuego(nombreV)) {
          cout << "no existe videojuego con ese nombre" <<endl;
          break;
        }
        DataVideojuego datav = sys->obtenerVideojuegoDesdeNombre(nombreV)->getDatos();
        cout << "Descripcion:" << datav.getDescripcion() << endl;
        cout << "Costo 1 mes: " << datav.getCosto().getCostoTemporal1mes() << " costo 3 meses: " << datav.getCosto().getCostoTemporal3mes() << " costo 12 meses: "  << datav.getCosto().getCostoTemporal12mes() << " costo vitalicia: " << datav.getCosto().getCostoVitalicia() << endl;
        cout << "Los generos son: " << endl;
        std::vector<std::string> gen = datav.getGeneros();  
        for (int i=0 ; i < gen.size(); i++) {
          cout << gen.at(i) <<endl;
        }
        cout << "Las plataformas son: " << endl;
        std::vector<std::string> pla = datav.getPlataformas();  
        for (int i=0 ; i < pla.size(); i++) {
          cout << pla.at(i) <<endl;
        }
        cout << "Las otras categorias son: " << endl;
        std::vector<std::string> otr = datav.getOtrasCategorias();  
        for (int i=0 ; i < otr.size(); i++) {
          cout << otr.at(i) <<endl;
        }
        cout << "Empresa del desarrollador: " << datav.getEmpresa() << endl;
        cout << "Puntaje promedio: " << datav.getPopularidad() << endl;
        cout << "Total horas jugadas: " << datav.gettotalHorasJugadas() <<endl;
        break;
      }
      case 7: { //Modificar fecha del sistema
        int a,b,c,d,e;
        cout << "Ingrese año: " <<endl;
        cin >> a;
        cout << "Ingrese mes: " <<endl;
        cin >> b;
        cout << "Ingrese dia: " <<endl;
        cin >> c;
        cout << "Ingrese hora: " <<endl;
        cin >> d;
        cout << "Ingrese minuto: " <<endl;
        cin >> e;
        TipoFechaHora nuevafecha = TipoFechaHora(a,b,c,d,e);
        SistemHandler* sys = SistemHandler::getInstancia();
        sys->setFechaSistema(nuevafecha);
        break;
      }
    }
  }
  while(opcion != 8);
}


void caso_2_jugador (std::istream& cin, std::ostream& cout) {

  int opcion = 8;

  do {
    cout<< "Ingrese opción (1: Suscribirse a videojuego, 2: Asignar puntaje a videojuego, 3: Iniciar partida, 4: Abandonar partida multijugador, 5: Finalizar partida, 6: Ver información de videojuego, 7: Modificar fecha del sisema, 8: Salir)" << std::endl;
    cin >> opcion;

    switch (opcion) {
      case 8: break; //salir
      case 1: { //Suscribirse a videojuego
        std::string NombreVaSuscribirse;
        std::vector<DataVideojuego> VjSus = Ucontroler->obtenerVideojuegosSus();
        std::vector<DataVideojuego> VjNoSus = Ucontroler->obtenerVideojuegosNoSus();
        cout << "Videojuegos con suscripcion activa: " <<endl;
        for (int i=0; i< VjSus.size(); i++) {
          std::string N = VjSus.at(i).getNombre();
          DataCosto C = VjSus.at(i).getCosto();
          cout << N <<" costo 1 mes: " << C.getCostoTemporal1mes() << " costo 3 meses: " << C.getCostoTemporal3mes() << " costo 12 meses: "  << C.getCostoTemporal12mes() << " costo vitalicia: " << C.getCostoVitalicia() <<endl;
        }
        cout << "Videojuegos sin suscripción activa: " <<endl;
        for (int i=0; i< VjNoSus.size(); i++) {
          std::string N = VjNoSus.at(i).getNombre();
          DataCosto C = VjNoSus.at(i).getCosto();
          cout << N <<" costo 1 mes: " << C.getCostoTemporal1mes() << " costo 3 meses: " << C.getCostoTemporal3mes() << " costo 12 meses: "  << C.getCostoTemporal12mes() << " costo vitalicia: " << C.getCostoVitalicia() <<endl;
        }
        cout << "Ingrese nombre de Videojuego a suscribirse " <<endl;
        std::getline(std::cin >> std::ws, NombreVaSuscribirse);
        try {
        Scontroler->setnombreVideojuegoASuscribirse(NombreVaSuscribirse);
        }
        catch (std::invalid_argument& e) {
          cout << e.what() <<endl;
          break;
        }
        bool res = false;
        Suscripcion* s = Ucontroler->devuelveSiTieneSusActivaUsuarioQueInicioSesion(NombreVaSuscribirse, res);
        if (res) { // ya tiene suscripcion activa para ese videojuego
          if (s->getDuracionMes() != 0) { // Sus actual es temporal
            int c;
            cout << "Desea cancelar sus sucripcion? (0 no, 1 si)" <<endl;
            cin >> c;
            if (c==0) { // No Desea cancelar
              Scontroler->cancelarSuscribirseAVideojuego();
              cout << "Accion cancelada" <<endl;
              break;
            }
            else { // Desea cancelar
              Scontroler->cancelarSuscripcionActual();
              goto pito;
            }
          }
          else { // sus actual es vitalicia
            Scontroler->cancelarSuscribirseAVideojuego();
            break;
          }
        }
        else { // no tiene suscripcion para ese videojuego y se crea nueva suscripcion
          pito:
            SistemHandler* sys = SistemHandler::getInstancia();
            int pago;
            int tipo;
            int confirmado;
            cout << "ingrese metodo de pago (0- Tarjeta, 1- Paypal)" <<endl;
            cin >> pago;
            MetodoPago metPago;
            if (pago == 0) {
              metPago = MetodoPago::TARJETA;
            }
            else {
              metPago = MetodoPago::PAY_PAL;
            }
            Scontroler->setmetodoParaPagarSuscripcionCreada(metPago);
            cout << "ingrese tipo de suscripcion (0- Vitalicia, 1- temporal 1 mes, 2- temporal 3 meses, 3- temporal 12 meses)" <<endl;
            cin >> tipo;
            Videojuego* videojuego = sys->obtenerVideojuegoDesdeNombre(NombreVaSuscribirse);
            DataSuscripcion* suscripcion;
            TipoFechaHora fecha = sys->getFechaSistema();
            if (tipo == 0) {
              suscripcion = new DataSuscripcion(fecha, videojuego->getCostoVitalicia(), 0, 0);
            }
            else if (tipo == 1) {
              suscripcion = new DataSuscripcion(fecha, videojuego->getCostoMensual(), 1, 1);
              //temporal 1 mes
            } else if (tipo == 2) {
              suscripcion = new DataSuscripcion(fecha, videojuego->getCostoTrimestral(), 1, 3);
              //temporal 3 meses
            } else {
              suscripcion = new DataSuscripcion(fecha, videojuego->getCostoAnual(), 1, 12);
              //temporal 12 meses
            }
            Scontroler->setsuscripcionQueSeEstaCreando(suscripcion);
            cout << "Confirma suscripción? (0- Si, 1- No)" <<endl;
            cin >> confirmado;
            if (confirmado == 0) {
              Scontroler->confirmarAltaSuscripcion();
              cout << "Suscripcion creada exitosamente" <<endl;
              break;
            }
            else {
              Scontroler->cancelarSuscribirseAVideojuego();
              cout << "Accion cancelada" <<endl;
              break;
            }
        }
        break;
      }
      case 2: { //Asignar puntaje a videojuego
        SistemHandler* sys = SistemHandler::getInstancia();
        int punto;
        std::string nick = sys->getnicknameDeUsuarioQueInicioSesion();
        std::string nombreV;
        std::vector<DataVideojuego> lista_juegos = sys->getlistaDeVideojuegos();
        for (int i=0; i< lista_juegos.size(); i++) {
          cout << lista_juegos.at(i).getNombre() << " --> " << lista_juegos.at(i).getDescripcion() << endl;
        }
        cout << "ingrese nombre del videojuego " <<endl;
        std::getline(std::cin >> std::ws, nombreV);
        cout << "ingrese puntaje (1...5) " << endl;
        cin >> punto;
        try {
          Ucontroler->crearPuntaje(punto, nick, nombreV);
        }
        catch (std::invalid_argument& e) {
          cout << e.what() <<endl;
          break;
        }
        cout << "Puntaje asignado correctamente" << endl;
        break;
      }
      case 3: { //Iniciar partida
        SistemHandler* sh = SistemHandler::getInstancia();
        std::vector<DataVideojuego> videojuegos = Ucontroler->obtenerVideojuegosSus();
        if (videojuegos.size() == 0) {
          cout << "No tiene suscripciones activas" <<endl;
          break;
        }
        cout << "Seleccione el videojuego" << endl;
        for(int i = 0; i < videojuegos.size(); i++){
          cout << videojuegos.at(i).getNombre() << endl;
        }
        string nombre;
        std::getline(std::cin >> std::ws, nombre);
        try {
          Pcontroler->seleccionarVideojuego(nombre);
        }
        catch (std::invalid_argument& e) {
          cout << e.what() <<endl;
          break;
        }
        cout << "Ingrese 0 si la partida a crear es individual y 1 en caso de que ésta sea multijugador." << endl;
        bool tipoPartida;
        cin >> tipoPartida;
        if(!tipoPartida){
          cout << "Ingrese 1 si la partida es continuación de una anterior, o 0 en caso contrario." << endl;
          bool continuacion;
          cin >> continuacion;
          if (continuacion){
            std::vector<DataPartida> partidasFin = Ucontroler->obtenerPartidasIndFin();
            cout << "Ingrese el identificador de la partida a continuar." << endl;
            for (int i = 0; i < partidasFin.size(); i++){
              cout << "Nombre Videojuego:" << partidasFin.at(i).getNombreVideojuego() << endl << " --> Fecha inicio: " << partidasFin.at(i).getFechaComienzo().getDia() << "/" <<  partidasFin.at(i).getFechaComienzo().getMes() << "/" << partidasFin.at(i).getFechaComienzo().getAnio() << " hora: " << partidasFin.at(i).getFechaComienzo().getHora() << ":" << partidasFin.at(i).getFechaComienzo().getMinuto() << endl << "La duracion es:" << partidasFin.at(i).getDuracion() << endl << "El identificador es:" << partidasFin.at(i).getIdentificador() << endl;
            }
            int continua;
            cin >> continua;
            Pcontroler->ingresarContinuacion(continua);
          }
          else{
            Pcontroler->identificadorPartidaIndNueva();
          }
        }
        else {
          cout << "Ingrese 1 si es transmitida en vivo, o 0 en caso contrario." <<endl;
          bool vivo;
          cin >> vivo;
          Pcontroler->transmitidaEnVivo(vivo);
          std::vector<std::string> jugadores = Pcontroler->jugadoresConSusActiva();
          cout << "Ingrese de a uno los nicknames de los jugadores unidos a la partida, cuando termine ingrese 0." << endl;
          for(int i = 0; i < videojuegos.size(); i++){
          cout << jugadores.at(i) << endl;
          }
          string lector;
          std::getline(std::cin >> std::ws, lector);
          while (lector != "0"){
            Pcontroler->agregarJugadores(lector);
            std::getline(std::cin >> std::ws, lector);
          }
          Pcontroler->identificadorPartidaMultiNueva();
        }
        cout << "Ingrese 1 si desea confirmar el alta de la partida, o 0 en caso de querer cancelarla." << endl;
        bool alta;
        cin >> alta;
        if(alta){
          Pcontroler->confirmarAltaPartida();
        }
        else{
          Pcontroler->cancelarAltaPartida();
        }
        break;
      }
      case 4: { //Abandonar partida multijugador
        SistemHandler* sys = SistemHandler::getInstancia();
        std::string nick = sys->getnicknameDeUsuarioQueInicioSesion();
        std::vector<DataPartidaMultijugador> datas = Ucontroler->obtenerPartidasMultiNoFinalizadas(nick);

        if (datas.size() == 0) {
          cout << "No hay partidas multijugador para abandonar"  << endl;
          break;
        }
        cout << "Lista de partidas multijugadores activas" <<endl;
        for (int i=0; i< datas.size(); i++) {
          cout << "Identificador: " << datas.at(i).getidentificador() << " --> Fecha inicio: " << datas.at(i).getfechaComienzo().getDia() << "/" <<  datas.at(i).getfechaComienzo().getMes() << "/" << datas.at(i).getfechaComienzo().getAnio() << " hora: " << datas.at(i).getfechaComienzo().getHora() << ":" << datas.at(i).getfechaComienzo().getMinuto() << " --> NombreVideojuego: " << datas.at(i).getnombreVideojuego() << " --> Transmitida en Vivo: " << datas.at(i).gettransmitidaEnVivo() << endl;
          cout << "Creador: " << datas.at(i).getcreadorNickname() << endl;
          std::vector<std::string> unidos = datas.at(i).getjugadoresUnidos();
          for (int i=0; i< unidos.size(); i++) {
            cout << "Jugador " << i << ": " << unidos.at(i) << endl;
          }
        }
        int idenPartida;
        cout << "Ingrese identificador de la Partida a abandonar"<< endl;
        cin >> idenPartida;
        try {
          Ucontroler->salirPartidaMultijugador(idenPartida);
        }
        catch (std::invalid_argument& e) {
          cout << e.what() <<endl;
          break;
        }
        cout << "Saliste de la partida exitosamente :) " <<endl;
        break;
      }
      case 5: { //Finalizar partida
        std::vector<DataPartida> partidasJug = Pcontroler->obtenerPartidasActuales();
        cout << "Ingresar identificador de partida a eliminar.";
        for (int i=0; i< partidasJug.size(); i++){
          cout << "Videojuego:" << partidasJug.at(i).getNombreVideojuego() << endl << "Fecha inicio: " << partidasJug.at(i).getFechaComienzo().getDia() << "/" <<  partidasJug.at(i).getFechaComienzo().getMes() << "/" << partidasJug.at(i).getFechaComienzo().getAnio() << " hora: " << partidasJug.at(i).getFechaComienzo().getHora() << ":" << partidasJug.at(i).getFechaComienzo().getMinuto() << endl << "Duracion:" << partidasJug.at(i).getDuracion() << endl << "Identificador:" << partidasJug.at(i).getIdentificador() << endl;
        }
        int identificador;
        cin >> identificador;
        Pcontroler->seleccionarPartida(identificador);
        Pcontroler->finalizarPartida();
        cout << "Partida finalizada existosamente." << endl;
        break;
      }
      case 6: { //Ver información de videojuego
        SistemHandler* sys = SistemHandler::getInstancia();
        std::string nombreV;
        std::vector<DataVideojuego> lista_juegos = sys->getlistaDeVideojuegos();
        cout << "Los videojuegos que hay en el sistema son: " << endl;
        for (int i=0; i< lista_juegos.size(); i++) {
          cout << lista_juegos.at(i).getNombre() << endl;
        }
        cout << "Ingrese nombre del videojuego a mostrar info" <<endl;
        std::getline(std::cin >> std::ws, nombreV);
        if (!sys->existeVideojuego(nombreV)) {
          cout << "no existe videojuego con ese nombre" <<endl;
          break;
        }
        DataVideojuego datav = sys->obtenerVideojuegoDesdeNombre(nombreV)->getDatos();
        cout << "Descripcion:" << datav.getDescripcion() << endl;
        cout << "Costo 1 mes: " << datav.getCosto().getCostoTemporal1mes() << " costo 3 meses: " << datav.getCosto().getCostoTemporal3mes() << " costo 12 meses: "  << datav.getCosto().getCostoTemporal12mes() << " costo vitalicia: " << datav.getCosto().getCostoVitalicia() << endl;
        cout << "Los generos son: " << endl;
        std::vector<std::string> gen = datav.getGeneros();  
        for (int i=0 ; i < gen.size(); i++) {
          cout << gen.at(i) <<endl;
        }
        cout << "Las plataformas son: " << endl;
        std::vector<std::string> pla = datav.getPlataformas();  
        for (int i=0 ; i < pla.size(); i++) {
          cout << pla.at(i) <<endl;
        }
        cout << "Las otras categorias son: " << endl;
        std::vector<std::string> otr = datav.getOtrasCategorias();  
        for (int i=0 ; i < otr.size(); i++) {
          cout << otr.at(i) <<endl;
        }
        cout << "Empresa del desarrollador: " << datav.getEmpresa() << endl;
        cout << "Puntaje promedio: " << datav.getPopularidad() << endl;
        break;
      }
      case 7: { //Modificar fecha del sistema
        int a,b,c,d,e;
        cout << "Ingrese año: " <<endl;
        cin >> a;
        cout << "Ingrese mes: " <<endl;
        cin >> b;
        cout << "Ingrese dia: " <<endl;
        cin >> c;
        cout << "Ingrese hora: " <<endl;
        cin >> d;
        cout << "Ingrese minuto: " <<endl;
        cin >> e;
        TipoFechaHora nuevafecha = TipoFechaHora(a,b,c,d,e);
        SistemHandler* sys = SistemHandler::getInstancia();
        sys->setFechaSistema(nuevafecha);
        break;
      }
    }
  } while(opcion != 8);
}

// Datos de prueba.

void caso_3 (std::istream& cin, std::ostream& cout) {
    SistemHandler* sh = SistemHandler::getInstancia();

    // Desarrolladores.
    Desarrollador* d1 = new Desarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
    sh->addDesarrollador(d1);
    Desarrollador* d2 = new Desarrollador("epic@mail.com", "123", "Epic Games");
    sh->addDesarrollador(d2);
    Desarrollador* d3 = new Desarrollador("mojang@mail.com", "123", "Mojang Studios");
    sh->addDesarrollador(d3);
    Desarrollador* d4 = new Desarrollador("ea@mail.com", "123", "EA Sports");
    sh->addDesarrollador(d4);

    // Jugadores.
    Jugador* j1 = new Jugador("gamer@mail.com", "123", "gamer", "");
    sh->addJugador(j1);
    Jugador* j2 = new Jugador("ari@mail.com", "123", "ari", "");
    sh->addJugador(j2);
    Jugador* j3 = new Jugador("ibai@mail.com", "123", "ibai", "");
    sh->addJugador(j3);
    Jugador* j4 = new Jugador("camila@mail.com", "123", "camila", "");
    sh->addJugador(j4);

    // Plataformas.
    Categoria* c1 = new Categoria("PC", "");
    sh->addPlataforma(c1);
    Categoria* c2 = new Categoria("PS4", "");
    sh->addPlataforma(c2);
    Categoria* c3 = new Categoria("Xbox One", "");
    sh->addPlataforma(c3);
    Categoria* c11 = new Categoria("Switch", "");
    sh->addPlataforma(c11);
    Categoria* c12 = new Categoria("Xbox X", "");
    sh->addPlataforma(c12);
    Categoria* c13 = new Categoria("PS5", "");
    sh->addPlataforma(c13);

    // Genero.
    Categoria* c4 = new Categoria("Deporte", "");
    sh->addGenero(c4);
    Categoria* c5 = new Categoria("Supervivencia", "");
    sh->addGenero(c5);
    Categoria* c6 = new Categoria("Estrategia", "");
    sh->addGenero(c6);
    Categoria* c9 = new Categoria("Accion", "");
    sh->addGenero(c9);
    Categoria* c10 = new Categoria("Aventura", "");
    sh->addGenero(c10);

    // Otro.
    Categoria* c7 = new Categoria("Teen", "Su contenido esta dirigido a jovenes de 13 anios en adelante");
    sh->addOtrasCat(c7);
    Categoria* c8 = new Categoria("E", "su contenido esta dirigido para todo publico");
    sh->addOtrasCat(c8);

    // Videojuegos.
    Videojuego* v1 = new Videojuego();
    Videojuego* v2 = new Videojuego();
    Videojuego* v3 = new Videojuego();
    Videojuego* v4 = new Videojuego();

    v1->setempresa(d1->getempresa());
    v2->setempresa(d2->getempresa());
    v3->setempresa(d3->getempresa());
    v4->setempresa(d4->getempresa());

    v1->setNombre("KingdomRush");
    v2->setNombre("Fortnite");
    v3->setNombre("Minecraft");
    v4->setNombre("FIFA 21");

    v1->setCostoMensual(1);
    v2->setCostoMensual(3);
    v3->setCostoMensual(2);
    v4->setCostoMensual(3);

    v1->setCostoTrimestral(2);
    v2->setCostoTrimestral(8);
    v3->setCostoTrimestral(5);
    v4->setCostoTrimestral(8);

    v1->setCostoAnual(7);
    v2->setCostoAnual(30);
    v3->setCostoAnual(20);
    v4->setCostoAnual(28);

    v1->setCostoVitalicia(7);
    v2->setCostoVitalicia(60);
    v3->setCostoVitalicia(40);
    v4->setCostoVitalicia(50);

    v1->addCategoria(c1);
    v1->addCategoria(c2);
    v1->addCategoria(c6);
    v1->addCategoria(c8);

    v2->addCategoria(c1);
    v2->addCategoria(c2);
    v2->addCategoria(c3);
    v2->addCategoria(c5);
    v2->addCategoria(c7);

    v3->addCategoria(c1);
    v3->addCategoria(c5);
    v3->addCategoria(c8);

    v4->addCategoria(c1);
    v4->addCategoria(c2);
    v4->addCategoria(c3);
    v4->addCategoria(c4);
    v4->addCategoria(c8);

    sh->agregarVideojuego(v1);
    sh->agregarVideojuego(v2);
    sh->agregarVideojuego(v3);
    sh->agregarVideojuego(v4);

    // Suscripcion
    Temporal* s1 = new Temporal(TipoFechaHora(21, 6, 1, 9, 0), v1->getCostoTrimestral(), MetodoPago::PAY_PAL, j1, v1, 3, false, false);
    Temporal* s2 = new Temporal(TipoFechaHora(21, 6, 2, 11, 0), v2->getCostoTrimestral(), MetodoPago::TARJETA, j1, v2, 3, false, false);
    Temporal* s3 = new Temporal(TipoFechaHora(21, 6, 4, 9, 0), v2->getCostoMensual(), MetodoPago::PAY_PAL, j2, v2, 1, false, false);
    Temporal* s4 = new Temporal(TipoFechaHora(21, 6, 11, 9, 0), v3->getCostoAnual(), MetodoPago::TARJETA, j2, v3, 12, false, false);
    Temporal* s5 = new Temporal(TipoFechaHora(21, 6, 3, 7, 0), v2->getCostoMensual(), MetodoPago::TARJETA, j3, v2, 1, false, false);
    Vitalicia* s6 = new Vitalicia(TipoFechaHora(20, 12, 21, 15, 0), v3->getCostoVitalicia(), MetodoPago::TARJETA, j3, v3);

    sh->agregarSuscripcion(s1);
    sh->agregarSuscripcion(s2);
    sh->agregarSuscripcion(s3);
    sh->agregarSuscripcion(s4);
    sh->agregarSuscripcion(s5);

    s1->setJugadorAsociado(j1);
    s2->setJugadorAsociado(j1);
    s3->setJugadorAsociado(j2);
    s4->setJugadorAsociado(j2);
    s5->setJugadorAsociado(j3);
    s6->setJugadorAsociado(j3);

    s1->setVideojuegoAsociado(v1);
    s2->setVideojuegoAsociado(v2);
    s3->setVideojuegoAsociado(v2);
    s4->setVideojuegoAsociado(v3);
    s5->setVideojuegoAsociado(v2);
    s6->setVideojuegoAsociado(v3);

    v1->agregarSuscripcion(s1);
    v2->agregarSuscripcion(s2);
    v2->agregarSuscripcion(s3);
    v2->agregarSuscripcion(s5);
    v3->agregarSuscripcion(s4);
    v3->agregarSuscripcion(s6);

    j1->getsuscripciones().push_back(s1);
    j1->getsuscripciones().push_back(s2);
    j2->getsuscripciones().push_back(s3);
    j2->getsuscripciones().push_back(s4);
    j3->getsuscripciones().push_back(s5);
    j3->getsuscripciones().push_back(s6);

    // Puntajes
    Puntos* p1 = new Puntos(4, j1, v1);
    Puntos* p2 = new Puntos(5, j1, v2);
    Puntos* p3 = new Puntos(5, j2, v2);
    Puntos* p4 = new Puntos(3, j1, v3);

    j1->agregarPuntaje(p1);
    v1->agregarPuntaje(p1);

    j1->agregarPuntaje(p2);
    v2->agregarPuntaje(p2);

    v2->agregarPuntaje(p3);
    j2->agregarPuntaje(p3);

    v3->agregarPuntaje(p4);
    j1->agregarPuntaje(p4);

    // Partidas Individuales.
    PartidaIndividual* i1 = new PartidaIndividual(TipoFechaHora(21, 6, 2, 9, 0), v1, j1, sh->getIdentNuevo(), false, nullptr);
    PartidaIndividual* i2 = new PartidaIndividual(TipoFechaHora(21, 6, 3, 15, 0), v1, j1, sh->getIdentNuevo(), true, i1);
    PartidaIndividual* i3 = new PartidaIndividual(TipoFechaHora(21, 6, 3, 16, 0), v3, j2, sh->getIdentNuevo(), false, nullptr);

    sh->agregarPartida(i1);
    sh->agregarPartida(i2);
    sh->agregarPartida(i3);

    v1->agregarPartida(i1);
    v1->agregarPartida(i2);
    v3->agregarPartida(i3);

    // Partidas Multijugador.
    PartidaMultijugador* m1 = new PartidaMultijugador(TipoFechaHora(21, 6, 5, 17, 0), v2, j1, sh->getIdentNuevo(), true);
    PartidaMultijugador* m2 = new PartidaMultijugador(TipoFechaHora(21, 6, 6, 17, 0), v2, j1, sh->getIdentNuevo(), true);
    PartidaMultijugador* m3 = new PartidaMultijugador(TipoFechaHora(21, 6, 12, 20, 0), v3, j2, sh->getIdentNuevo(), false);

    sh->setFechaSistema(TipoFechaHora(21, 6, 5, 19, 0));
    m1->finalizarPartida();
    m2->finalizarPartida();

    sh->asociarParJs(m1, {"gamer", "ari"});
    sh->asociarParJs(m2, {"gamer", "ari"});
    sh->asociarParJs(m3, {"ibai"});

    sh->agregarPartida(m1);
    sh->agregarPartida(m2);
    sh->agregarPartida(m3);
}
