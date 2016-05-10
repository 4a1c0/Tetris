#include "IteradorNodeJugador.h"



IteradorNodeJugador::IteradorNodeJugador()
{
    m_posicio = NULL;
}

IteradorNodeJugador::IteradorNodeJugador(NodeJugador* posicio)
{
    m_posicio = posicio;
}

void IteradorNodeJugador::seguent()
{
    m_posicio = m_posicio->getNext();
}

bool IteradorNodeJugador::esNul() const
{
    return m_posicio == NULL;
}

Jugador &IteradorNodeJugador::getElement() const
{
    return m_posicio->getValor();
}
