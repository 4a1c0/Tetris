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

    // Heu de modificar el valor de l'atribut m_posX (posició x de la figura) amb el valor posX que es passa com a paràmetre
    m_posX = posX;

}

void FigTetris::setPosY(int posY)
{

    // Heu de modificar el valor de l'atribut m_posY (posició y de la figura) amb el valor posY que es passa com a paràmetre
    m_posY = posY;

}

void FigTetris::draw()
{

    // Heu e dibuixar el gràfic de la figura del tetris a la posicio m_posX, m_posY
    m_figura[m_gir].Draw(m_posX, m_posY);
}

void FigTetris::crearMascara()
{
    m_mascara = new bool**[m_girs];

    for(int i = 0; i < m_girs; i++)
    {
        m_mascara[i] = new bool*[MAX_MASCARA];
        for(int j = 0; j<MAX_MASCARA; j++)
        {
            m_mascara[i][j] = new bool[MAX_MASCARA];
            for(int k = 0; k < MAX_MASCARA; k++)
            {
                m_mascara[i][j][k] = false;
            }
        }
    }
}
void FigTetris::destruirMascara()
{
     for(int i = 0; i < m_girs; i++)
    {

        for(int j = 0; j < MAX_MASCARA; j++)
        {
            delete[] m_mascara[i][j];

        }
        delete[] m_mascara[i];
    }
    delete[] m_mascara;

    m_mascara = NULL;
}


void FigTetris::create(int indexFig,int gir)
{

    // Heu de crear una de les figures del tetris en funció de l'índex que es passa com a paràmetre
    // A continuació teniu el gràfic que heu d'utilitzar per cada possible valor de indexFig
    // I: ("data/Graficstetris/palblaucel1.png")
    // O:("data/Graficstetris/q4groc1.png")
    // T:("data/Graficstetris/tmagenta2.png")
    // L:("data/Graficstetris/ltaronja2.png")
    // P:("data/Graficstetris/pblaufosc4.png")
    // S:("data/Graficstetris/sverd1.png")
    // Z:("data/Graficstetris/zroig1.png")
    // Per cada figura, a més a més de crear el gràfic heu d'inicialitzar la resta dels atributs de la classe (amplada, alçada, index i color)

    //Inicialitzar la mascara a false





    //definir gir

    m_gir = gir;



    switch (indexFig)
    {
        case O:

            m_figura[0].Create("data/Graficstetris/q4groc1.png");

            m_indexFig = indexFig;
            m_color = COLOR_GROC;
            m_girs = 1;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][0][1]=true;
            m_mascara[0][1][0]=true;
            m_mascara[0][1][1]=true;
            m_amplada[0] = 2;
            m_gir = 0;


            break;
        case L:
            m_figura[0].Create("data/Graficstetris/ltaronja1.png");
            m_figura[1].Create("data/Graficstetris/ltaronja2.png");
            m_figura[2].Create("data/Graficstetris/ltaronja3.png");
            m_figura[3].Create("data/Graficstetris/ltaronja4.png");

            m_indexFig = indexFig;
            m_color = COLOR_TARONJA;
            m_girs = 4;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][0][1]=true;
            m_mascara[0][1][1]=true;
            m_mascara[0][2][1]=true;
            m_amplada[0] = 3;
            m_mascara[1][0][2]=true;
            m_mascara[1][1][0]=true;
            m_mascara[1][1][1]=true;
            m_mascara[1][1][2]=true;
            m_amplada[2] = 3;
            m_mascara[2][0][0]=true;
            m_mascara[2][1][0]=true;
            m_mascara[2][2][0]=true;
            m_mascara[2][2][1]=true;
            m_amplada[2] = 2;
            m_mascara[3][0][0]=true;
            m_mascara[3][0][1]=true;
            m_mascara[3][0][2]=true;
            m_mascara[3][1][0]=true;
            m_amplada[3] = 3;



            break;
        case Z:
            m_figura[0].Create("data/Graficstetris/zroig1.png");
            m_figura[1].Create("data/Graficstetris/zroig2.png");

            m_indexFig = indexFig;
            m_color = COLOR_ROIG;

            m_girs = 2;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][0][1]=true;
            m_mascara[0][1][1]=true;
            m_mascara[0][1][2]=true;
            m_amplada[0] = 3;
            m_mascara[1][0][1]=true;
            m_mascara[1][1][0]=true;
            m_mascara[1][1][1]=true;
            m_mascara[1][2][0]=true;
            m_amplada[1] = 2;

            m_gir = gir%2;


            break;
        case T:
            m_figura[0].Create("data/Graficstetris/tmagenta1.png");
            m_figura[1].Create("data/Graficstetris/tmagenta2.png");
            m_figura[2].Create("data/Graficstetris/tmagenta3.png");
            m_figura[3].Create("data/Graficstetris/tmagenta4.png");

            m_indexFig = indexFig;
            m_color = COLOR_MAGENTA;

            m_girs = 4;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][1][0]=true;
            m_mascara[0][2][0]=true;
            m_mascara[0][1][1]=true;
            m_amplada[0] = 2;
            m_mascara[1][0][1]=true;
            m_mascara[1][1][0]=true;
            m_mascara[1][1][1]=true;
            m_mascara[1][1][2]=true;
            m_amplada[1] = 3;
            m_mascara[2][0][1]=true;
            m_mascara[2][1][0]=true;
            m_mascara[2][1][1]=true;
            m_mascara[2][2][1]=true;
            m_amplada[2] = 2;
            m_mascara[3][0][0]=true;
            m_mascara[3][0][1]=true;
            m_mascara[3][0][2]=true;
            m_mascara[3][1][1]=true;
            m_amplada[3] = 3;
            break;

        case S:
            m_figura[0].Create("data/Graficstetris/sverd1.png");
            m_figura[1].Create("data/Graficstetris/sverd2.png");

            m_indexFig = indexFig;
            m_color = COLOR_VERD;

            m_girs = 2;

            crearMascara();

            m_mascara[0][0][1]=true;
            m_mascara[0][0][2]=true;
            m_mascara[0][1][0]=true;
            m_mascara[0][1][1]=true;
            m_amplada[0] = 3;
            m_mascara[1][0][0]=true;
            m_mascara[1][1][0]=true;
            m_mascara[1][1][1]=true;
            m_mascara[1][2][1]=true;
            m_amplada[1] = 3;

            m_gir = gir%2;

            break;
        case I:
            m_figura[0].Create("data/Graficstetris/palblaucel1.png");
            m_figura[1].Create("data/Graficstetris/palblaucel2.png");

            m_indexFig = indexFig;
            m_color = COLOR_BLAUCEL;

            m_girs = 2;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][1][0]=true;
            m_mascara[0][2][0]=true;
            m_mascara[0][3][0]=true;
            m_amplada[0] = 1;
            m_mascara[1][0][0]=true;
            m_mascara[1][0][1]=true;
            m_mascara[1][0][2]=true;
            m_mascara[1][0][3]=true;
            m_amplada[1] = 4;

            m_gir = gir%2;

            break;
        case P:
            m_figura[0].Create("data/Graficstetris/pblaufosc1.png");
            m_figura[1].Create("data/Graficstetris/pblaufosc2.png");
            m_figura[2].Create("data/Graficstetris/pblaufosc3.png");
            m_figura[3].Create("data/Graficstetris/pblaufosc4.png");

            m_indexFig = indexFig;
            m_color = COLOR_BLAUFOSC;

            m_girs = 4;

            crearMascara();

            m_mascara[0][0][0]=true;
            m_mascara[0][1][0]=true;
            m_mascara[0][2][0]=true;
            m_mascara[0][0][1]=true;
            m_amplada[0] = 2;
            m_mascara[1][0][0]=true;
            m_mascara[1][0][1]=true;
            m_mascara[1][0][2]=true;
            m_mascara[1][1][2]=true;
            m_amplada[1] = 3;
            m_mascara[2][0][1]=true;
            m_mascara[2][1][1]=true;
            m_mascara[2][2][1]=true;
            m_mascara[2][2][0]=true;
            m_amplada[2] = 2;
            m_mascara[3][0][0]=true;
            m_mascara[3][1][0]=true;
            m_mascara[3][1][1]=true;
            m_mascara[3][1][2]=true;
            m_amplada[3] = 3;
            break;
        default:
            break;

    }

}

int FigTetris::amplada()
{

    // Retorna l'amplada de la figura
    return m_amplada [m_gir];
}

int FigTetris::alcada()
{

    // Retorna l'alçada de la figura
    return m_alcada;
}

bool FigTetris::gir(Fons& fons)
{
    bool correcte = false;;
    switch (m_indexFig)
    {
        case O:
            correcte = true;
            break;
        case Z:
        case S:
        case I:



            if (!fons.solapa(m_mascara[(m_gir + 1)%2], m_posX / MIDA_Q , m_posY / MIDA_Q, 0, 0))
            {
                m_gir = (m_gir + 1)%2;
                correcte = true;
            }

            break;
            break;
            break;
        default:
            if (!fons.solapa(m_mascara[(m_gir + 1)%4], m_posX / MIDA_Q , m_posY / MIDA_Q, 0, 0))
            {
                m_gir = (m_gir + 1)%4;
                correcte = true;
            }

            break;

    }

    return correcte;

 }

bool FigTetris::moureFig(int dirX, int dirY, Fons& fons)
{

    // Heu d'analitzar si es pot fer el moviment indicat a dirX i dirY en funció de l'estat del fons i de la posició actual de la figura.
    // Si el moviment és possible, haure de modificar com correspongui el valor dels atributs m_posX i m_posY per actualitzar la posició
    // de la figura d'acord al moviment indicat. La funció ha de retornar true si la figura ha arribat a l'última línia del tauler

    // Els valors de dirX i dirX que indiquen el moviment poden ser de moment:
    // -1, 0: moviment a l'esquerra. Aqui sempre retornem fals.
    // 1, 0: moviment a la dreta. Aqui sempre retornem fals.
    // 0, 1: moviment a baix. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.
    // 0, 2: moviment a baix de dues posicions. Aqui a més hem de veure si ja hem arribat a baix de tot. Si hem arribat retornarem true,
    //       i actualitzarem la última línia del tauler del fons amb els quadres del color de la figura actual.

    bool arribada = false;



    if ((dirX == -1) && !(fons.solapa(m_mascara[m_gir], m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) // ESQUERRA: mirem si la peca es mou a l'esquerra a partir de l'eix X
        m_posX -= MIDA_Q;

    if ((dirX == 1) && !(fons.solapa(m_mascara[m_gir], m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) //DRETA: mirem si es pot moure amb coordenades + amplada i final de taulell
        m_posX += MIDA_Q;

    if (dirY == 1)
    {
        if(!(fons.solapa(m_mascara[m_gir], m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))) //ABAIX Normal (1 pos): mirem els límits
        m_posY += MIDA_Q;
        else if (fons.solapa(m_mascara[m_gir], m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY))//Si la peca es troba a la última fila es crida figuraEncaixada i es retorna true
        {
            figuraEncaixada(fons);
            arribada = true;
        }
    }

    if ((dirY == 2) && !(fons.solapa(m_mascara[m_gir], m_posX / MIDA_Q , m_posY / MIDA_Q, dirX, dirY) )) //ABAIX Tecla (2 pos): mirem limits
        m_posY += 2 * MIDA_Q;

    return arribada;
}

void FigTetris::figuraEncaixada(Fons& fons)
{


	// Modifica els quadres corresponents a l'amplada de la figura actual a les posicions de la última línia del tauler el fons amb els colors de la figura actual

        for(int i = 0; i < MAX_MASCARA; i++)
        {
            for(int j = 0; j < MAX_MASCARA; j++)
            {
                if(m_mascara[m_gir][i][j])
                {
                      fons.setTauler(m_posY / MIDA_Q + i,  m_posX / MIDA_Q  + j, m_color);
                }
            }
        }

}
