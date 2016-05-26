#include "IteradorNodeJugador.h"

IteradorNodeJugador::IteradorNodeJugador()
{
    m_posicio = nullptr;
}

IteradorNodeJugador::IteradorNodeJugador(NodeJugador* posicio)
{
    m_posicio = posicio;
}

IteradorNodeJugador::~IteradorNodeJugador()
{
    //dtor
}

void IteradorNodeJugador::seguent(void)
{
	m_posicio = m_posicio->getNext();
}

Jugador IteradorNodeJugador::getJugador(void)
{
    return m_posicio -> getJugador();
}

bool IteradorNodeJugador::esNul(void) const
{
	return (m_posicio == nullptr);
}

NodeJugador *IteradorNodeJugador::getNode(void) const
{
	return m_posicio;
}
