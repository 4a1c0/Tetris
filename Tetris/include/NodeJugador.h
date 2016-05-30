#ifndef NODEJUGADOR_H
#define NODEJUGADOR_H

#include "Jugador.h"

class NodeJugador
{
    public:
        NodeJugador();
        ~NodeJugador();
        NodeJugador* getNext(void) const;
        void setNext(NodeJugador*);
        Jugador getJugador(void);
        void setJugador(char nom[], int punts);
        void setJug(Jugador jug);



    private:

    NodeJugador* m_next;
    Jugador m_jugador;
};

#endif // NODEJUGADOR_H
