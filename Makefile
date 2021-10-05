SRC_DIR=src
INC_DIR=include
BIN_DIR=bin
TEST_DIR=test

OBJ_ROOT=obj

CXXFLAGS=-I $(INC_DIR)

.PHONY: default

# main
default:\
	$(OBJ_ROOT)/data/DataPartidaIndividual.o\
	$(OBJ_ROOT)/data/DataJugador.o\
	$(OBJ_ROOT)/data/DataCategoria.o\
	$(OBJ_ROOT)/data/TipoFechaHora.o\
	$(OBJ_ROOT)/data/DataDesarrollador.o\
	$(OBJ_ROOT)/data/DataPartida.o\
	$(OBJ_ROOT)/data/DataUsuario.o\
	$(OBJ_ROOT)/data/DataEstadistica.o\
	$(OBJ_ROOT)/data/DataComentario.o\
	$(OBJ_ROOT)/data/DataVideojuego.o\
	$(OBJ_ROOT)/data/DataSuscripcion.o\
	$(OBJ_ROOT)/data/DataPartidaMultijugador.o\
	$(OBJ_ROOT)/data/DataCosto.o\
	$(OBJ_ROOT)/suscripcion/Suscripcion.o\
	$(OBJ_ROOT)/suscripcion/Vitalicia.o\
	$(OBJ_ROOT)/suscripcion/Temporal.o\
	$(OBJ_ROOT)/usuario/Usuario.o\
	$(OBJ_ROOT)/usuario/Jugador.o\
	$(OBJ_ROOT)/usuario/Desarrollador.o\
	$(OBJ_ROOT)/partida/Partida.o\
	$(OBJ_ROOT)/partida/PartidaIndividual.o\
	$(OBJ_ROOT)/partida/PartidaMultijugador.o\
	$(OBJ_ROOT)/Categoria.o\
	$(OBJ_ROOT)/Fabrica.o\
	$(OBJ_ROOT)/Puntos.o\
	$(OBJ_ROOT)/Unidos.o\
	$(OBJ_ROOT)/Videojuego.o\
	$(OBJ_ROOT)/estadistica/MetodoSuscripcionesTotales.o\
	$(OBJ_ROOT)/estadistica/Estadistica.o\
	$(OBJ_ROOT)/estadistica/MetodoHorasJugadas.o\
	$(OBJ_ROOT)/estadistica/MetodoPopularidad.o\
	$(OBJ_ROOT)/SistemHandler.o\
	$(OBJ_ROOT)/partidaCtrl/PartidaCtrl.o\
	$(OBJ_ROOT)/videojuegoCtrl/VideojuegoCtrl.o\
	$(OBJ_ROOT)/usuarioCtrl/UsuarioCtrl.o\
	$(OBJ_ROOT)/suscribirseCtrl/SuscribirseCtrl.o\
	$(OBJ_ROOT)/main.o\
	$(BIN_DIR)
	$(CXX) $(CXXFLAGS)\
		$(OBJ_ROOT)/data/DataPartidaIndividual.o\
		$(OBJ_ROOT)/data/DataJugador.o\
		$(OBJ_ROOT)/data/DataCategoria.o\
		$(OBJ_ROOT)/data/TipoFechaHora.o\
		$(OBJ_ROOT)/data/DataDesarrollador.o\
		$(OBJ_ROOT)/data/DataPartida.o\
		$(OBJ_ROOT)/data/DataUsuario.o\
		$(OBJ_ROOT)/data/DataEstadistica.o\
		$(OBJ_ROOT)/data/DataComentario.o\
		$(OBJ_ROOT)/data/DataVideojuego.o\
		$(OBJ_ROOT)/data/DataSuscripcion.o\
		$(OBJ_ROOT)/data/DataPartidaMultijugador.o\
		$(OBJ_ROOT)/data/DataCosto.o\
		$(OBJ_ROOT)/suscripcion/Suscripcion.o\
		$(OBJ_ROOT)/suscripcion/Vitalicia.o\
		$(OBJ_ROOT)/suscripcion/Temporal.o\
		$(OBJ_ROOT)/usuario/Usuario.o\
		$(OBJ_ROOT)/usuario/Jugador.o\
		$(OBJ_ROOT)/usuario/Desarrollador.o\
		$(OBJ_ROOT)/partida/Partida.o\
		$(OBJ_ROOT)/partida/PartidaIndividual.o\
		$(OBJ_ROOT)/partida/PartidaMultijugador.o\
		$(OBJ_ROOT)/Categoria.o\
		$(OBJ_ROOT)/Fabrica.o\
		$(OBJ_ROOT)/Puntos.o\
		$(OBJ_ROOT)/Unidos.o\
		$(OBJ_ROOT)/Videojuego.o\
		$(OBJ_ROOT)/estadistica/MetodoSuscripcionesTotales.o\
		$(OBJ_ROOT)/estadistica/Estadistica.o\
		$(OBJ_ROOT)/estadistica/MetodoHorasJugadas.o\
		$(OBJ_ROOT)/estadistica/MetodoPopularidad.o\
		$(OBJ_ROOT)/SistemHandler.o\
		$(OBJ_ROOT)/partidaCtrl/PartidaCtrl.o\
		$(OBJ_ROOT)/videojuegoCtrl/VideojuegoCtrl.o\
		$(OBJ_ROOT)/usuarioCtrl/UsuarioCtrl.o\
		$(OBJ_ROOT)/suscribirseCtrl/SuscribirseCtrl.o\
		$(OBJ_ROOT)/main.o\
		-o $(BIN_DIR)/p4lab4

# codigo objeto
$(OBJ_ROOT)/%.o: $(SRC_DIR)/%.cpp $(OBJ_ROOT)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/data/%.o: $(SRC_DIR)/data/%.cpp $(OBJ_ROOT)/data
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/estadistica/%.o: $(SRC_DIR)/estadistica/%.cpp $(OBJ_ROOT)/estadistica
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/partida/%.o: $(SRC_DIR)/partida/%.cpp $(OBJ_ROOT)/partida
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/suscripcion/%.o: $(SRC_DIR)/suscripcion/%.cpp $(OBJ_ROOT)/suscripcion
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/usuario/%.o: $(SRC_DIR)/usuario/%.cpp $(OBJ_ROOT)/usuario
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/categoria/%.o: $(SRC_DIR)/categoria/%.cpp $(OBJ_ROOT)/categoria
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/usuarioCtrl/%.o: $(SRC_DIR)/usuarioCtrl/%.cpp $(OBJ_ROOT)/usuarioCtrl
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/videojuegoCtrl/%.o: $(SRC_DIR)/videojuegoCtrl/%.cpp $(OBJ_ROOT)/videojuegoCtrl
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/suscribirseCtrl/%.o: $(SRC_DIR)/suscribirseCtrl/%.cpp $(OBJ_ROOT)/suscribirseCtrl
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_ROOT)/partidaCtrl/%.o: $(SRC_DIR)/partidaCtrl/%.cpp $(OBJ_ROOT)/partidaCtrl
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# carpeta bin y obj
$(OBJ_ROOT):
	mkdir -p $(OBJ_ROOT)

$(OBJ_ROOT)/data: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/data

$(OBJ_ROOT)/estadistica: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/estadistica

$(OBJ_ROOT)/partida: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/partida

$(OBJ_ROOT)/suscripcion: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/suscripcion

$(OBJ_ROOT)/usuario: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/usuario

$(OBJ_ROOT)/categoria: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/categoria

$(OBJ_ROOT)/usuarioCtrl: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/usuarioCtrl

$(OBJ_ROOT)/videojuegoCtrl: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/videojuegoCtrl

$(OBJ_ROOT)/suscribirseCtrl: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/suscribirseCtrl

$(OBJ_ROOT)/partidaCtrl: $(OBJ_ROOT)
	mkdir -p $(OBJ_ROOT)/partidaCtrl

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
