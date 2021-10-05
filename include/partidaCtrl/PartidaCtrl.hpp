#ifndef PARTIDACTRL_H
#define PARTIDACTRL_H

#include <partidaCtrl/IPartida.hpp>

class PartidaCtrl : public IPartida {
  private:
		bool individual;
		bool continuacion;
		int* ident;
		bool enVivo;
		std::vector<std::string> jugadoresUnidos;
		std::string* videojuegoPartidaACrear;
  public:
		std::string getVideojuegoPartidaACrear();
		bool getContinuacion();
		bool getIndividual();
		int getIdent();
		bool getEnVivo();
		std::vector<std::string> getJugadoresUnidos();
    std::vector<DataPartida> obtenerPartidasActuales();
    void seleccionarPartida(int identificador);
    void finalizarPartida();
    void seleccionarVideojuego(std::string nombre);
    void ingresarContinuacion(int identificador);
    void identificadorPartidaIndNueva();
    void transmitidaEnVivo(bool trans);
    std::vector<std::string> jugadoresConSusActiva();
    void agregarJugadores(std::string nick);
    void identificadorPartidaMultiNueva();
    void confirmarAltaPartida();
    void cancelarAltaPartida();
};

#endif