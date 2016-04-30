#include "FigTetris.h"

FigTetris::FigTetris()
{
    // Constructor. No s'ha de modificar
}

FigTetris::~FigTetris()
{
    // Destructor. No s'ha de modificar
}

void FigTetris::setPosX(int posX)
{

    // Heu de modificar el valor de l'atribut m_posX (posici� x de la figura) amb el valor posX que es passa com a par�metre
    m_posX = posX;

}

void FigTetris::setPosY(int posY)
{

    // Heu de modificar el valor de l'atribut m_posY (posici� y de la figura) amb el valor posY que es passa com a par�metre
    m_posY = posY;

}

void FigTetris::draw()
{

    // Heu e dibuixar el gr�fic de la figura del tetris a la posicio m_posX, m_posY
    m_figura.Draw(m_posX, m_posY);
}

void FigTetris::create(int indexFig)
{

    // Heu de crear una de les figures del tetris en funci� de l'�ndex que es passa com a par�metre
    // A continuaci� teniu el gr�fic que heu d'utilitzar per cada possible valor de indexFig
    // I: ("data/Graficstetris/palblaucel1.png")
    // O:("data/Graficstetris/q4groc1.png")
    // T:("data/Graficstetris/tmagenta2.png")
    // L:("data/Graficstetris/ltaronja2.png")
    // P:("data/Graficstetris/pblaufosc4.png")
    // S:("data/Graficstetris/sverd1.png")
    // Z:("data/Graficstetris/zroig1.png")
    // Per cada figura, a m�s a m�s de crear el gr�fic heu d'inicialitzar la resta dels atributs de la classe (amplada, al�ada, index i color)

    //Inicialitzar la mascara a false

    for(int i = 0; i < MAX_MASCARA; i++)
    {
        for(int j = 0; j<MAX_MASCARA; j++)
        {
            m_mascara[i][j] = false;
        }
    }

    switch (indexFig)
    {
        case O:
            m_figura.Create("data/Graficstetris/q4groc1.png");
            m_amplada = 2;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_GROC;
            m_mascara[0][0]=true;
            m_mascara[0][1]=true;
            m_mascara[1][0]=true;
            m_mascara[1][1]=true;

            break;
        case L:
            m_figura.Create("data/Graficstetris/ltaronja2.png");
            m_amplada = 3;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_TARONJA;

            m_mascara[0][2]=true;
            m_mascara[1][0]=true;
            m_mascara[1][1]=true;
            m_mascara[1][2]=true;

            break;
        case Z:
            m_figura.Create("data/Graficstetris/zroig1.png");
            m_amplada = 3;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_ROIG;
            m_mascara[0][0]=true;
            m_mascara[0][1]=true;
            m_mascara[1][1]=true;
            m_mascara[1][2]=true;

            break;
        case T:
            m_figura.Create("data/Graficstetris/tmagenta2.png");
            m_amplada = 3;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_MAGENTA;
            m_mascara[0][1]=true;
            m_mascara[1][0]=true;
            m_mascara[1][1]=true;
            m_mascara[1][2]=true;
            break;
        case S:
            m_figura.Create("data/Graficstetris/sverd1.png");
            m_amplada = 3;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_VERD;
            m_mascara[0][1]=true;
            m_mascara[0][2]=true;
            m_mascara[1][0]=true;
            m_mascara[1][1]=true;
            break;
        case I:
            m_figura.Create("data/Graficstetris/palblaucel1.png");
            m_amplada = 1;
            m_alcada = 4;
            m_indexFig = indexFig;
            m_color = COLOR_BLAUCEL;
            m_mascara[0][0]=true;
            m_mascara[1][0]=true;
            m_mascara[2][0]=true;
            m_mascara[3][0]=true;
            break;
        case P:
            m_figura.Create("data/Graficstetris/pblaufosc4.png");
            m_amplada = 3;
            m_alcada = 2;
            m_indexFig = indexFig;
            m_color = COLOR_BLAUFOSC;
            m_mascara[0][0]=true;
            m_mascara[1][0]=true;
            m_mascara[1][1]=true;
            m_mascara[1][2]=true;
            break;
        default:
            break;

    }

}

int FigTetris::amplada()
{

    // Retorna l'amplada de la figura
    return m_amplada;
}

int FigTetris::alcada()
{

    // Retorna l'al�ada de la figura
    return m_alcada;
}

bool FigTetris::moureFig(int dirX, int dirY, Fons& fons)
{

    // Heu d'analitzar si es pot fer el moviment indicat a dirX i dirY en funci� de l'estat del fons i de la posici� actual de la figura.
    // Si el moviment �s possible, haure de modificar com correspongui el valor dels atributs m_posX i m_posY per actualitzar la posici�
    // de la figura d'acord al moviment indicat. La funci� ha de retornar true si la figura ha arribat a l'�ltima l�nia del tauler

    // Els valors de dirX i dirX que indiquen el moviment poden ser de moment:
    // -1, 0: moviment a l'esquerra. Aqui sempre retornem fals.
    // 1, 0: moviment a la dreta. Aqui sempre retornem fals.
    // 0, 1: moviment a baix. Aqui a m�s hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la �ltima l�nia del tauler del fons amb els quadres del color de la figura actual.
    // 0, 2: moviment a baix de dues posicions. Aqui a m�s hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la �ltima l�nia del tauler del fons amb els quadres del color de la figura actual.

    bool arribada = false;



    if ((dirX == -1) && !(fons.solapa(m_mascara, m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) // ESQUERRA: mirem si la peca es mou a l'esquerra a partir de l'eix X
        m_posX -= MIDA_Q;

    if ((dirX == 1) && !(fons.solapa(m_mascara, m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) //DRETA: mirem si es pot moure amb coordenades + amplada i final de taulell
        m_posX += MIDA_Q;

    if (dirY == 1)
    {
        if(!(fons.solapa(m_mascara, m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) //ABAIX Normal (1 pos): mirem els l�mits
        m_posY += MIDA_Q;
        else if (fons.solapa(m_mascara, m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))//Si la peca es troba a la �ltima fila es crida figuraEncaixada i es retorna true
        {
            figuraEncaixada(fons);
            arribada = true;
        }
    }

    if ((dirY == 2) && !(fons.solapa(m_mascara, m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY) )) //ABAIX Tecla (2 pos): mirem limits
        m_posY += 2 * MIDA_Q;

    return arribada;
}

void FigTetris::figuraEncaixada(Fons& fons)
{


	// Modifica els quadres corresponents a l'amplada de la figura actual a les posicions de la �ltima l�nia del tauler el fons amb els colors de la figura actual

        for(int i = 0; i < MAX_MASCARA; i++)
        {
            for(int j = 0; j < MAX_MASCARA; j++)
            {
                if(m_mascara[i][j])
                {
                      fons.setTauler(m_posY / MIDA_Q + i,  m_posX / MIDA_Q  + j, m_color);
                }
            }
        }

}
