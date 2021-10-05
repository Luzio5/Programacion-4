#ifndef FABRICA_H
#define FABRICA_H

#include <partidaCtrl/IPartida.hpp>
#include <suscribirseCtrl/ISuscribirse.hpp>
#include <videojuegoCtrl/IVideojuego.hpp>
#include <usuarioCtrl/IUsuario.hpp>
#include <partidaCtrl/PartidaCtrl.hpp>
#include <suscribirseCtrl/SuscribirseCtrl.hpp>
#include <usuarioCtrl/UsuarioCtrl.hpp>
#include <videojuegoCtrl/VideojuegoCtrl.hpp>

class Fabrica {
    public:
        IPartida* createIPartida();
        ISuscribirse* createISuscribirse();
        IVideojuego* createIVideojuego();
        IUsuario* createIUsuario();
};

#endif