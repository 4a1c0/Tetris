#ifndef NODEJUGADOR_H_INCLUDED
#define NODEJUGADOR_H_INCLUDED

#include "Jugador.h"

class NodeJugador
{
    public:
        NodeJugador();
        ~NodeJugador();
        Jugador& getValor();
        NodeJugador* getNext() const;
        void setValor(Jugador &valor);
        void setNext(NodeJugador* next);
    private:
        Jugador m_valor;
        NodeJugador* m_next;


};

#endif // NODEJUGADOR_H_INCLUDED
