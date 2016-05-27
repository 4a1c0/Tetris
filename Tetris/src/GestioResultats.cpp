#include "GestioResultats.h"

Ranking::Ranking()
{
    //ctor
}

Ranking::~Ranking()
{
    //dtor
}



void Ranking::inicialitzar()
{
    m_rankingJugadors.inicialitza();
}

void Ranking::afegirJugador(int punts)
{
    system("cls");


    char nom[MAX_LONG_NOM];
    IteradorNodeJugador actItJug = m_rankingJugadors.getInici();
    IteradorNodeJugador antItJug = nullptr;

    printf("Entra el teu nom\n");
    scanf("%16[^\n]",&nom);
    fflush(stdin);

    if (m_rankingJugadors.esBuida())
    {
        actItJug = m_rankingJugadors.insereixNext(nom, punts, actItJug);
        actItJug.seguent();
    }


    while ((!m_rankingJugadors.esBuida()) && (!actItJug.esNul()))
    {

        if (actItJug.getJugador().getPuntuacio()>=punts)
            {
                antItJug=actItJug;
                actItJug.seguent();

                if (actItJug.esNul())
                    antItJug = m_rankingJugadors.insereixNext(nom, punts, antItJug);
            }
        else
            {
                actItJug = m_rankingJugadors.insereixNext(nom, punts, antItJug);
                antItJug=actItJug;
                actItJug.seguent();

            }

        }

}

void Ranking::escriuRanking()
{
    system("cls");

    IteradorNodeJugador ItJug = m_rankingJugadors.getInici();
    int pos = 1;
	cout << "---- Millors Puntuacions ---- \n";

    while((!m_rankingJugadors.esBuida()) && (!ItJug.esNul()))
    {
        cout << endl << pos<<".- ";
        ItJug.getNode()->getJugador().printar();
        pos++;
        ItJug.seguent();
    }
    cout << "----------------------------- \n";
}

void Ranking::desar(const char* nomFitxer)
{
    m_rankingJugadors.desar(nomFitxer);
}

void Ranking::llegir(const char* nomFitxer)
{
    m_rankingJugadors.llegir(nomFitxer);
}

