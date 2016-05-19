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

int IteradorNodeJugador::getValor(void) const
{
    return m_posicio -> getValor();
}

bool IteradorNodeJugador::esNul(void) const
{
	return (m_posicio == nullptr);
}

NodeJugador *IteradorNodeJugador::getNode(void) const
{
	return m_posicio;
}
