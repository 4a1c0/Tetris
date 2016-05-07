#ifndef LLISTAJUGADOR_H_INCLUDED
#define LLISTAJUGADOR_H_INCLUDED

#include "IteradorNodeJugador.h"
#include "NodeJugador.h"

class LlistaJugador
{
    public:
        LlistaJugador();
        ~LlistaJugador();

        IteradorNodeJugador insereixNext(Jugador &valor, IteradorNodeJugador posicio);
        IteradorNodeJugador eliminarNext(IteradorNodeJugador posicio);
        IteradorNodeJugador getInici() const;
        bool esBuida() const;

    private:
        NodeJugador *m_primer;
};


#endif // LLISTAJUGADOR_H_INCLUDED
