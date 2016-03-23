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
    // TODO
    // Heu e dibuixar el gr�fic de la figura del tetris a la posicio m_posX, m_posY
    m_figura.Draw(m_posX, m_posY);
}

void FigTetris::create(int indexFig)
{
    // TODO
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

    switch (indexFig)
    {
        case O:
            m_figura.Create("data/Graficstetris/q4groc1.png");

            break;
        case 1:
            m_figura.Create("data/Graficstetris/ltaronja2.png");


            break;
        case 2:
            m_figura.Create("data/Graficstetris/zroid1.png");


            break;
        case 3:
            m_figura.Create("data/Graficstetris/tmagenta2.png");


            break;
        case 4:
            m_figura.Create("data/Graficstetris/sverd1.png");


            break;
        case 5:
            m_figura.Create("data/Graficstetris/palblaucel1.png");

            break;
        case 6:
            m_figura.Create("data/Graficstetris/pblaufosc4.png");

            break;
        default:
            break;

    }

}

int FigTetris::amplada()
{
    // TODO
    // Retorna l'amplada de la figura
    return m_amplada;
}

int FigTetris::alcada()
{
    // TODO
    // Retorna l'al�ada de la figura
    return m_alcada;
}

bool FigTetris::moureFig(int dirX, int dirY, Fons& fons)
{
    // TODO:
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

}

void FigTetris::figuraEncaixada(Fons& fons)
{
	// TODO:
	// Aquest m�tode s'ha de cridar quan la figura arriba a baix de tot.
	// Modifica els quadres corresponents a l'amplada de la figura actual a les posicions de la �ltima l�nia del tauler el fons amb els colors de la figura actual
}
