#include "Menu.h"
#include "Joc.h"
#include "GestioResultats.h"
#include <conio.h>      /* getch */

const char JUGAR = '1';
const char CONFIGURAR = '2';
const char PUNTUACIO = '3';
const char SORTIR = '4';


int main()
{
	Ranking rankingJugadors;
	rankingJugadors.inicialitzar();

    char opcio;
    char nivell = '1';
	do{
		menuPrincipal();
		opcio = _getch();

		int punts;

		switch(opcio)
		{
			case JUGAR:
			    punts = joc(nivell-'0');

				rankingJugadors.afegirJugador(punts);
				break;

			case CONFIGURAR:
				do{
                    menuNivellDificultat();
					nivell =_getch();
					if ((nivell != '1') && (nivell != '2') && (nivell != '3'))
					{
						printf("Opcio incorrecta.\n");
					}
				} while((nivell != '1') && (nivell != '2') && (nivell != '3'));
				break;
			case PUNTUACIO:
				rankingJugadors.escriuRanking();
				printf("\n Prem una tecla per tornar al menu principal");
				_getch();
				break;
		}
	}while(opcio != SORTIR);

	return 0;
}
