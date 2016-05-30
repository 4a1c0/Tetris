#include "LlistaJugador.h"

LlistaJugador::LlistaJugador()
{
    inicialitza();
}

LlistaJugador::~LlistaJugador()
{
    finalitza();
}

void LlistaJugador::inicialitza()
{
	m_primer = nullptr;
}

void LlistaJugador::finalitza()
{
	while (m_primer != nullptr)
	{
		eliminaNext(IteradorNodeJugador(nullptr));
	}
}

IteradorNodeJugador LlistaJugador::insereixNext(char nom[], int punts, IteradorNodeJugador posicio)
{
	NodeJugador* aux;

	aux = new NodeJugador  ;
	aux->setJugador(nom, punts);

	if (posicio.esNul())
	{
		aux->setNext(m_primer);
		m_primer = aux;
	}
	else
	{
		aux->setNext(posicio.getNode()->getNext());
		posicio.getNode()->setNext(aux);
	}
	return aux;
}

void LlistaJugador::eliminaNext(IteradorNodeJugador posicio)
{
	NodeJugador* aux;

	if (posicio.esNul())
	{
		aux = m_primer;
		m_primer = m_primer->getNext();
	}
	else
	{
		aux = posicio.getNode()->getNext();
		posicio.getNode()->setNext(aux->getNext());
	}
	delete aux;
}

bool LlistaJugador::esBuida() const
{
	return (m_primer == nullptr);
}

IteradorNodeJugador LlistaJugador::getInici() const
{
	return IteradorNodeJugador(m_primer);
}

IteradorNodeJugador LlistaJugador::insereixll(Jugador jugador, IteradorNodeJugador posicio)
{
	NodeJugador* aux;

	aux = new NodeJugador();
	aux->setJug(jugador);

	if (posicio.esNul())
	{
		aux->setNext(m_primer);
		m_primer = aux;
	}
	else
	{
		aux->setNext(posicio.getNode()->getNext());
		posicio.getNode()->setNext(aux);
	}
	return aux;
}

void LlistaJugador::desar(const char* nomFitxer)
{
        ofstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        IteradorNodeJugador itJug = getInici();
        if(!esBuida())
        {
            itJug.getJugador().desar(fitxer);
            itJug.seguent();

        }

        while(!itJug.esNul())
        {
            fitxer<<"\n";
            itJug.getJugador().desar(fitxer);
            itJug.seguent();
        }

        fitxer.close();
    }
}

void LlistaJugador::llegir(const char* nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    {
        IteradorNodeJugador itJug = getInici();

        while(!fitxer.eof())
        {
            Jugador jug;
            jug.llegir(fitxer);
            itJug = insereixll(jug, itJug);

        }

        fitxer.close();
    }
}
