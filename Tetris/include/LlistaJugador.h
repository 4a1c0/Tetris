#ifndef LLISTAJUGADOR_H
#define LLISTAJUGADOR_H
#include "IteradorNodeJugador.h"


class LlistaJugador
{
    public:
        LlistaJugador();
        ~LlistaJugador();

        void inicialitza();
        void finalitza();

        IteradorNodeJugador insereixNext(char nom[], int punts, IteradorNodeJugador posicio);
        void eliminaNext(IteradorNodeJugador posicio);

        IteradorNodeJugador getInici() const;
        bool esBuida() const;

        void desar(const char*);
        void llegir(const char*);

    protected:

    private:
        NodeJugador* m_primer;

};

#endif // LLISTAJUGADOR_H
