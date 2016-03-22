#include "Fons.h"

Fons::Fons()
{
    // Constructor. No s'ha de modificar.
    // Crea els gr�fics que s'utilitzaran per dibuixar els quadrats de colors al tauler a mesura que les figures vagin arribant a baix de tot
    m_quadrats[COLOR_GROC].Create("data/Graficstetris/q1groc.png");
    m_quadrats[COLOR_TARONJA].Create("data/Graficstetris/q1taronja.png");
    m_quadrats[COLOR_ROIG].Create("data/Graficstetris/q1roig.png");
    m_quadrats[COLOR_MAGENTA].Create("data/Graficstetris/q1magenta.png");
    m_quadrats[COLOR_VERD].Create("data/Graficstetris/q1verd.png");
    m_quadrats[COLOR_BLAUCEL].Create("data/Graficstetris/q1blaucel.png");
    m_quadrats[COLOR_BLAUFOSC].Create("data/Graficstetris/q1blaufosc.png");
}

Fons::~Fons()
{
    // Destructor. No s'ha de modificar
}

void Fons::inicialitzar(const char *rutaFons)
{
    // TODO
    // Heu de crear l'Sprite amb el dibuix del fons del tauler
    // Tamb� heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la �ltima fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler est� buit. Per fer-ho podeu utilitzar
    // els m�todes posarNegre() i posarGris()


}
void Fons::posarNegre()
{
    // TODO
    // Heu d'inicialitzar totes les posicions interiors (que no s�n l�mits) de la matriu m_tauler a negre

}

void Fons::posarGris()
{
    // TODO
    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la �ltima fila de la matriu m_tauler a gris

}

void Fons::pintaFons()
{
    // TODO:
    // Heu de pintar tots els quadres del fons del tauler que que no s�n negres i que per tant corresponen a figures que ja s'han col�locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'�litima l�nia del tauler
    // Recoreu que els quares grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.
}

void Fons::setTauler(int fila, int columna, int color)
{
    // TODO
    // Heu de modificar el valor de color de la posici� fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a par�metre.
}


bool Fons::guanyar()
{
	// TODO
	// Heu de retornar cert si la �ltima l�nia del tauler que no est� gris est� tota pintada de colors
	// i fals si hi ha algun quadre a negre.
}
