#include "Jugador.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::Jugador (char nom[], int punts)
{
    for (int  i = 0; i < MAX_LONG_NOM; i++)
        m_nom[i] = nom[i];
    m_puntuacio = punts;
}

Jugador::~Jugador()
{
    //dtor
}

int Jugador::getPuntuacio()
{
    return m_puntuacio;
}

void Jugador::printar()
{
    cout << m_nom << " ---- " << m_puntuacio << endl;
}

void Jugador::desar(ofstream&)
{

}

void Jugador::llegir(ifstream&)
{

}
