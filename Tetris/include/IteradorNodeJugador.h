#ifndef ITERADORNODEJUGADOR_H_INCLUDED
#define ITERADORNODEJUGADOR_H_INCLUDED


#include "NodeJugador.h"


class IteradorNodeJugador
{
    public:
        IteradorNodeJugador();
        IteradorNodeJugador(NodeJugador* posicio);
        ~IteradorNodeJugador();
        Jugador &getElement() const;
        void seguent();
        bool esNul() const;

    private:
        NodeJugador m_posicio;
};


#endif // ITERADORNODEJUGADOR_H_INCLUDED
