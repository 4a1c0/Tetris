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

int NodeJugador::getValor(void) const
{
	return m_valor;
}

void NodeJugador::setValor(int valor)
{
	m_valor = valor;
}
