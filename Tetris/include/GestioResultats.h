#ifndef GESTIORESULTATS_H_INCLUDED
#define GESTIORESULTATS_H_INCLUDED

#include "LlistaJugador.h"

class Ranking
{
    public:
        Ranking();
        ~Ranking();
        void inicialitzar();
        void afegirJugador(int punts);
        void escriuRanking();
    private:
        LlistaJugador m_rankingJugadors;

};
#endif // GESTIORESULTATS_H_INCLUDED

