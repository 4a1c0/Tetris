#ifndef GESTIORESULTATS_H_INCLUDED
#define GESTIORESULTATS_H_INCLUDED

class Ranking
{
    public:
        Ranking();
        ~Ranking();
        void inicialitzar();
        void afegirJugador(int punts);
        void escriuRanking();
    private:
        LlistaJugadors m_rankingJugadors;

};
#endif // GESTIORESULTATS_H_INCLUDED

