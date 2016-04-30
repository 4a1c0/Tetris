#ifndef RESULTATS_H
#define RESULTATS_H

#include "../lib/libreria.h"

// Posició de la graella per nostrar puntuacio i nivell;
const int POS_RESX = 350;
const int POS_RESY = 340; // _350

// Posicio de les centenes dels punts i del pas d'una unitat a una altre.
const int POS_PUNTS_RESX = 530;
const int POS_PUNTS_RESY = 475; //_485
const int PAS_DIGIT_X = 20;

// Posicio del nivell
const int POS_NIV_RESX = 530; // Canvi de 550 a 530 per a centrar
const int POS_NIV_RESY = 420; // _430

//Posicio de les vides
const int POS_VIDES_X = 530;
const int POS_VIDES_Y = 525;

class Resultats
{
    public:
        Resultats();
        virtual ~Resultats();
        void inicialitzar(const char*);
        void pintaResultats(int , int, int);

    protected:
    private:
        Sprite m_resultats;
        Sprite m_digits[10];
        void escriuDigit(int , int , int );
        void escriuNumero(int ,int ,int ,int );
};

#endif // RESULTATS_H
