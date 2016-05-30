#include "NodeJugador.h"

NodeJugador::NodeJugador()
{
    //ctor
}

NodeJugador::~NodeJugador()
{
    //dtor
}

NodeJugador* NodeJugador::getNext(void) const
{
	return m_next;
}

void NodeJugador::setNext(NodeJugador* node)
{
	m_next = node;
}

Jugador NodeJugador::getJugador(void)
{

	return m_jugador;
}

void NodeJugador::setJugador(char nom[], int punts)
{
    m_jugador = Jugador(nom, punts);
}

void NodeJugador::setJug(Jugador jug)
{
    m_jugador = jug;
}
