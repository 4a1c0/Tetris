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
    posarGris();
    posarNegre();



}
void Fons::posarNegre()
{

    // Heu d'inicialitzar totes les posicions interiors (que no són límits) de la matriu m_tauler a negre

    for (int i = 0; i < MAX_FILA - 3; i++)
    {
        for (int j = 1; j < MAX_COL - 5; j++) //?? No acabo de veure lo dels límits del taulell
        {
            m_tauler[i][j] = COLOR_NEGRE;
        }
    }

}

void Fons::posarGris()
{

    // Heu d'inicialitzar primera i ultima columnes de la matriu m_tauler a gris
    // Heu d'inicialitzar la última fila de la matriu m_tauler a gris

    for (int i = MAX_FILA - 3; i < MAX_FILA ; i++)
    {
        for(int j = 3; j < MAX_COL - 3; j++)
        {
            m_tauler[i][j] = COLOR_GRIS;
        }

    }

    for(int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            m_tauler[i][j] = COLOR_GRIS;
            m_tauler[i][MAX_COL - j - 1] = COLOR_GRIS;
        }
    }




}

void Fons::pintaFons()
{

    // Heu de pintar tots els quadres del fons del tauler que que no són negres i que per tant corresponen a figures que ja s'han col·locat al tauler.
    // De moment, tots els quadres de color (no negres) estaran a l'úlitima línia del tauler
    // Recoreu que els quares grisos del tauler ja estan pintats a la imatge del fons i no els heu de tornar a dibuixar.


        m_fons.Draw(0,0);

        for(int i = 0; i < MAX_FILA - 3; i++)
        {
            for (int j = 1; j < MAX_COL - 5; j++)
            {
                if (m_tauler[i][j] != COLOR_NEGRE)
                {
                    m_quadrats[m_tauler[i][j]].Draw(j*MIDA_Q, i*MIDA_Q);
                }
            }

        }

}

void Fons::setTauler(int fila, int columna, int color)
{

    // Heu de modificar el valor de color de la posició fila, columna del tauler (valor de la matriu m_tauler) amb el color que es passa com a paràmetre.

    m_tauler[fila][columna] = color;


}

void Fons::moureTauler(int fila, int tauler[][MAX_COL])
{
    int fila_aux [MAX_COL - 5];
    for (int j = 0; j < MAX_COL - 5; j++)
        tauler[fila][j] = COLOR_NEGRE;

    for(int i = fila; i > 0; i--)
    {
        for (int j = 1; j < MAX_COL - 5; j++)
        {
            fila_aux[j] = tauler[i][j];
            tauler[i][j] = tauler [i - 1][j];
            tauler[i - 1][j] = fila_aux[j];
        }
    }


}


bool Fons::guanyar(int &fcompletes)
{

	// Heu de retornar cert si la última línia del tauler que no està gris està tota pintada de colors
	// i fals si hi ha algun quadre a negre.


	bool complet;
	fcompletes=0;


    for(int i = 0; i < MAX_FILA - 3; i++)
    {
        complet = true;
        for (int j = 1; j < MAX_COL - 5; j++)
        {
            if (m_tauler[i][j] == COLOR_NEGRE)
            complet = false;
            if (j == MAX_COL - 6 && complet == true)
            {
                moureTauler(i, m_tauler);
                fcompletes++;
            }




        }


    }

    return fcompletes > 0;
}

bool Fons::solapa(bool** mascara, int posX, int posY, int dirX, int dirY)
{
    bool solapa = false;


        for(int i = 0; i < MAX_MASCARA; i++)
        {
            for(int j = 0; j < MAX_MASCARA; j++)
            {
                if(mascara[i][j] && (m_tauler[posY + i + dirY][posX + j + dirX] != COLOR_NEGRE))
                {
                        return true;
                }
            }
        }
return solapa;

}
