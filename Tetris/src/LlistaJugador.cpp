#include "LlistaJugador.h"

LlistaJugador::LlistaJugador()
{
    m_primer = NULL;
}

LlistaJugador::~LlistaJugador()
{
    IteradorNodeJugador posicio(NULL);
    while(m_primer != NULL)
        eliminarNext(posicio);
}

bool LlistaJugador::esBuida() const
{
    return m_primer == NULL;
}

IteradorNodeJugador LlistaJugador::getInici() const
{
    return IteradorNodeJugador(m_primer);
}

IteradorNodeJugador LlistaJugador::insereixNext(Jugador &valor, IteradorNodeJugador posicio)
{
    NodeJugador* aux = new NodeJugador;

    if (aux != NULL)
    {
        aux->setValor(valor);
        if (posicio.esNul())
        {
            aux->setNext(m_primer);
            m_primer = aux;
        }
        else
        {
            NodeJugador* actual = posicio.getNode();
            aux->setNext(actual->getNext());
            actual->setNext(aux);
        }
    }

    return IteradorNodeJugador(aux);
}

IteradorNodeJugador LlistaJugador::eliminarNext(IteradorNodeJugador posicio)
{
    NodeJugador* aux;
    IteradorNodeJugador itSeguent;
    if (posicio.esNul())
    {
        itSeguent = IteradorNodeJugador(m_primer->getNext());
        aux = m_primer;
        m_primer = aux->getNext();
        delete aux;
    }
    else
    {
        aux = posicio.getNode()->getNext();
        itSeguent = IteradorNodeJugador(aux->getNext());
        posicio.getNode()->setNext(aux->getNext());
        delete aux;
    }

    return itSeguent;
}
