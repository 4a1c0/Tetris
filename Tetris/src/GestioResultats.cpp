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


/*
void inicialitzarTaulaMillorJugadors(TipusJugador tMillorsJugadors[])
{
	for(int i = 0; i < MAX_MILLORS_JUGADORS; i++)
	{
		strcpy(tMillorsJugadors[i].Nom,"--------------");
		tMillorsJugadors[i].puntuacio = 0;
	}
}



int esMillorPuntuacio(TipusJugador tMillorsJugadors[], int punts)
{
	int i=0;
	int trobat=0;

	do
	{
		if(tMillorsJugadors[i].puntuacio < punts)
		{
			trobat = 1;
		}
		i++;

	}while ((i < MAX_MILLORS_JUGADORS) && (!trobat));

	if (trobat)
	{
		return (i - 1);
	}
	else
	{
		return - 1;
	}
}

void desplacarArray(TipusJugador tMillorsJugadors[], int posicio)
{
	for (int i = MAX_MILLORS_JUGADORS - 1; i > posicio; i--)
	{
		strcpy(tMillorsJugadors[i].Nom, tMillorsJugadors[i - 1].Nom);
		tMillorsJugadors[i].puntuacio = tMillorsJugadors[i - 1].puntuacio;
	}
}

void emplenarPosicioArray(TipusJugador& tMillorsJugadors,int punts)
{ //IMPORTANT, APROFITABLE DE CARA A LA CONTINUACIÓ
	system("cls");
	printf("Entra el teu nom\n");
	scanf("%16[^\n]",&nom);
	fflush(stdin);
	//IMPORTANT, APROFITABLE DE CARA A LA CONTINUACIÓ
}

void escriuRanking(TipusJugador tMillorsJugadors[])
{
	system("cls");
	for(int i = 0; i < MAX_MILLORS_JUGADORS; i++)
	{
		printf("%d.- %s %d\n", i + 1, tMillorsJugadors[i].Nom, tMillorsJugadors[i].puntuacio);
	}

}
*/

