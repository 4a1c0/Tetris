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

    for (int j = 0; j < MAX_FILA - 3; j++)
    {
        for (int i = 3; i < MAX_COL - 3; i++)
        {
            m_tauler[i][j] = COLOR_NEGRE;
        }
    }

}

void Fons::posarGris()
{

    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la última fila de la matriu m_tauler a gris

    for (int i = 0; i < MAX_COL; i++)
    {
        for(int j = MAX_FILA - 3; j < MAX_FILA; j++)
        {
            m_tauler[i][j] = COLOR_GRIS;
        }

    }

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < MAX_FILA; j++)
        {

            m_tauler[i][j] = COLOR_GRIS;
            m_tauler[MAX_COL - i][j] = COLOR_GRIS;
        }
    }




}

void Fons::pintaFons()
{

    // Heu de pintar tots els quadres del fons del tauler que que no són negres i que per tant corresponen a figures que ja s'han col·locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'úlitima línia del tauler
    // Recoreu que els quares grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.

        int j = MAX_FILA - 2; // degut a que de moment nomes fem servir la ultima fila

        m_fons.Draw(0,0);

        for(int i = 1; i < MAX_COL - 1; i++)
        {
            if (m_tauler[i][j] != COLOR_NEGRE)
            {
                m_quadrats[m_tauler[i][j]].Draw(i*MIDA_Q, j*MIDA_Q);
            }
        }

}

void Fons::setTauler(int fila, int columna, int color)
{

    // Heu de modificar el valor de color de la posició fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a paràmetre.

    m_tauler[fila][columna] = color;


}


bool Fons::guanyar()
{

	// Heu de retornar cert si la última línia del tauler que no està gris està tota pintada de colors
	// i fals si hi ha algun quadre a negre.


	bool complet = true;

	int j = MAX_FILA - 4; // degut a que de moment nomes fem servir la ultima fila
    for(int i = 3; i < MAX_COL - 3; i++)
    {
        if (m_tauler[i][j] == COLOR_NEGRE)
            complet = false;
    }

    return complet;
}

bool Fons::solapa(bool mascara[][MAX_MASCARA], int posX, int posY, int dirX, int dirY)
{
    bool solapa false;


        for(int i = 0; i < MAX_MASCARA; i++)
        {
            for(int j = 0; j < MAX_MASCARA; j++)
            {
                while(mascara[i][j])
                {
                    if (m_tauler[posX + i + dirX][posY + j + dirY] != COLOR_NEGRE)
                        solapa = true;
                }
            }
        }




}
