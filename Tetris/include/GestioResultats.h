#ifndef GESTIORESULTATS_H_INCLUDED
#define GESTIORESULTATS_H_INCLUDED

#include "LlistaJugador.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Ranking
{
    public:
        Ranking();
        ~Ranking();
        void inicialitzar();
        void afegirJugador(int punts);
        void escriuRanking();
        void desar(const char*);
        void llegir(const char*);
    private:
        LlistaJugador m_rankingJugadors;

};
#endif // GESTIORESULTATS_H_INCLUDED

