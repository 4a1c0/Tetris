#include "Fons.h"



Fons::Fons()
{
    // Constructor. No s'ha de modificar.
    // Crea els gràfics que s'utilitzaran per dibuixar els quadrats de colors al tauler a mesura que les figures vagin arribant a baix de tot
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

    // Heu de crear l'Sprite amb el dibuix del fons del tauler
    // També heu d'inicialitzar totes les posicions de la matriu m_tauler  a color negre, excepte la primera i ultima columna
    // i la última fila que s'han d'inicialitzar a gris. D'aquesta manera marquem que tot el tauler està buit. Per fer-ho podeu utilitzar
    // els mètodes posarNegre() i posarGris()

    m_fons.Create(rutaFons);
    posarNegre();
    posarGris();


}
void Fons::posarNegre()
{

    // Heu d'inicialitzar totes les posicions interiors (que no són límits) de la matriu m_tauler a negre

    for (int j = 0; j < MAX_FILA - 1; j++)
    {
        for (int i = 1; i < MAX_COL -1; i++)
        {
            m_tauler[j][i] = COLOR_NEGRE;
        }
    }

}

void Fons::posarGris()
{

    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la última fila de la matriu m_tauler a gris

    for (int i = 0; i < MAX_COL; i++)
    {
        m_tauler[MAX_FILA][i] = COLOR_GRIS;
    }


    for (int j = 0; j < MAX_FILA; j++)
    {
        m_tauler[j][0] = COLOR_GRIS;
        m_tauler[j][MAX_COL] = COLOR_GRIS;
    }



}

void Fons::pintaFons()
{
    // TODO:
    // Heu de pintar tots els quadres del fons del tauler que que no són negres i que per tant corresponen a figures que ja s'han col·locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'úlitima línia del tauler
    // Recoreu que els quares grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.

        int j = MAX_FILA - 2; // degut a que de moment nomes fem servir la ultima fila

        m_fons.Draw(0,0);

        for(int i = 1; i < MAX_COL - 1; i++)
        {
            if (m_tauler[j][i] != COLOR_NEGRE)
            {
                m_quadrats[m_tauler[j][i]].Draw(i*MIDA_Q, (j + 1)*MIDA_Q);
            }
        }

}

void Fons::setTauler(int fila, int columna, int color)
{
    // TODO
    // Heu de modificar el valor de color de la posició fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a paràmetre.

    m_tauler[fila][columna] = color;

}


bool Fons::guanyar()
{
	// TODO
	// Heu de retornar cert si la última línia del tauler que no està gris està tota pintada de colors
	// i fals si hi ha algun quadre a negre.


	bool complet = false;
    int i = 1;
	int j = MAX_FILA - 2; // degut a que de moment nomes fem servir la ultima fila
	while(m_tauler[j][i] != COLOR_NEGRE && i < MAX_COL)
    {
        complet = true;
        i++;
    }
    return complet;
}
