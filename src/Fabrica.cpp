#include <Fabrica.hpp>

IPartida* Fabrica::createIPartida() {
    return new PartidaCtrl();
}

ISuscribirse* Fabrica::createISuscribirse() {
    return new SuscribirseCtrl();
}

IVideojuego* Fabrica::createIVideojuego() {
    return new VideojuegoCtrl();
}

IUsuario* Fabrica::createIUsuario() {
    return new UsuarioCtrl();
}
