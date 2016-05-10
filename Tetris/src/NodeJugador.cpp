#include "NodeJugador.h"
Jugador& NodeJugador::getValor()
{
    return m_valor;
}

NodeJugador* NodeJugador::getNext() const
{
    return m_next;
}
void NodeJugador::setValor(Jugador& valor)
{
    m_valor =valor;
}

void NodeJugador::setNext(NodeJugador* next)
{
    m_next = next;
}
